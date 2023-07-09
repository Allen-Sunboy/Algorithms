#include <iostream>
#include <opencv2/opencv.hpp>

#include <chrono>

using namespace cv;
using namespace std;
using namespace std::chrono;

Mat imgNew;

int s[5003][5003];
int result[5003][5003];

int seam[5003];

void cut_seam()
{
    Mat gradX, gradY, grad;

    int channel = imgNew.channels();

    Sobel(imgNew, gradX, CV_64F, 1, 0);
    Sobel(imgNew, gradY, CV_64F, 0, 1);

    convertScaleAbs(gradX, gradX);
    convertScaleAbs(gradY, gradY);
    addWeighted(gradX, 0.5, gradY, 0.5, 0, grad);

    if(channel == 3)
        cvtColor(grad, grad, COLOR_BGR2GRAY);

    int row = imgNew.rows;
    int col = imgNew.cols;

    for(int j = 0; j < col; j++)
        s[0][j] = (int)grad.at<uchar>(0, j);
    
    for(int i = 1; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            if(j == 0)
            {
                s[i][j] = min(s[i-1][j], s[i-1][j+1]) + (int)grad.at<uchar>(i, j);
                int p = j;
                if(s[i-1][p] > s[i-1][j+1])
                    p = j+1;
                result[i][j] = p;
            }
                
            else if(j == col - 1)
            {
                s[i][j] = min(s[i-1][j-1], s[i-1][j]) + (int)grad.at<uchar>(i, j);
                int p = j-1;
                if(s[i-1][p] > s[i-1][j])
                    p = j;
                result[i][j] = p;

            }
            else
            {
                s[i][j] = min(s[i-1][j-1], min(s[i-1][j], s[i-1][j+1])) + (int)grad.at<uchar>(i, j);
                int p = j-1;
                if(s[i-1][p] > s[i-1][j])
                    p = j;
                if(s[i-1][p] > s[i-1][j+1])
                    p = j+1;
                result[i][j] = p;
            }
        }
    }

    int q = 0;
    for(int j = 0; j < col; j++)
        if(s[row-1][q] > s[row-1][j])
            q = j;
    seam[row-1] = q;

    for(int i = row - 1; i >= 1; i--)
        seam[i-1] = result[i][seam[i]];

    Mat mask = Mat::ones(row, col, CV_8U);
    for(int i = 0; i < row; i++)
        mask.at<uchar>(i, seam[i]) = 0;

    Mat temp = Mat(row, col-1, imgNew.type());

    for(int i = 0; i < row; i++)
    {
        int k = 0;
        for(int j = 0; j < col; j++)
        {
            if (mask.at<uchar>(i, j) != 0)
                temp.at<Vec3b>(i, k++) = imgNew.at<Vec3b>(i, j);
        }
    }

    temp.copyTo(imgNew);
}

void func()
{
    int row = imgNew.rows;
    int col = imgNew.cols;

    for(int i = 0; i < col / 2; i++)
        cut_seam();
    
    transpose(imgNew, imgNew);

    for(int i = 0; i < row / 2; i++)
        cut_seam();

    transpose(imgNew, imgNew);

}

int main()
{
    string imgPath;
    getline(cin, imgPath);
    Mat img = imread(imgPath);
    if(img.empty())
    {
        cout << "invalid path or empty image" << endl;
        return 0; 
    }

    imgNew = img.clone();

    auto start = chrono::steady_clock::now();

    func();

    auto end = chrono::steady_clock::now();

    auto dur = duration_cast<seconds>(end - start);

    cout << dur.count() << " (second)" << endl;

    string imgType = imgPath.substr(imgPath.find_last_of(".") + 1);

    auto now = chrono::system_clock::now();
    auto current = chrono::duration_cast<chrono::seconds>(now.time_since_epoch());
    string imgNewName = to_string(current.count());

    imgNewName += "." + imgType;
    imwrite(imgNewName, imgNew);

    cout << "Done!";

    imshow(imgNewName, imgNew);
    waitKey();
    destroyAllWindows();

}