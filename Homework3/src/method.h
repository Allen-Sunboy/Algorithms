#include <QPair>

#ifndef METHOD_H
#define METHOD_H

struct point
{
    long long x;
    long long y;
};
point points[1000007];

//存储数组的点和原先的下标
QPair<point, long long> points_num[1000007];

long long amount;

//两个点之间的距离的平方
long long distance_square(point a, point b)
{
    long long result = (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
    return result;
}

//暴力法
QPair<QPair<long long, long long>, long long> closest_1()
{
    long long a = 0, b = 1;
    long long d = distance_square(points[0], points[1]);
    for(int i = 0; i < amount; i++)
    {
        for(int j = i + 1; j < amount; j++)
        {
            long long temp = distance_square(points[i], points[j]);
            if(temp < d)
            {
                a = i;
                b = j;
                d = temp;
            }
        }
    }
    return QPair(QPair(a, b), d);
}

void quickSortX(point points[], int p, int r)
{
    if(p < r)
    {
        auto x = points[r];
        int i = p - 1;
        for(int j = p; j < r; j++)
        {
            if(points[j].x <= x.x)
            {
                i++;
                std::swap(points[i], points[j]);
            }
        }
        std::swap(points[i+1], points[r]);
        quickSortX(points, p, i);
        quickSortX(points, i+2, r);
    }
}

void quickSortY(QPair<point, long long> points_num[], int p, int r)
{
    if(p < r)
    {
        auto x = points_num[r];
        int i = p - 1;
        for(int j = p; j < r; j++)
        {
            if(points_num[j].first.y <= x.first.y)
            {
                i++;
                std::swap(points_num[i], points_num[j]);
            }
        }
        std::swap(points_num[i+1], points_num[r]);
        quickSortY(points_num, p, i);
        quickSortY(points_num, i+2, r);
    }
}

//分治，合并
QPair<QPair<long long, long long>, long long> solve(point points[], int l, int h)
{
    if(h - l == 1)
        return QPair(QPair(l, h), distance_square(points[l], points[h]));
    if(h - l == 2)
    {
        long long d12 = distance_square(points[l], points[l+1]);
        long long d23 = distance_square(points[l+1], points[h]);
        long long d13 = distance_square(points[l], points[h]);
        if(d12 < d23 && d12 < d13)
            return QPair(QPair(l, l+1), d12);
        else if(d23 < d13)
            return QPair(QPair(l+1, h), d23);
        else
            return QPair(QPair(l, h), d13);
    }
    int m = (l + h) / 2;
    QPair<QPair<long long, long long>, long long> q1 = solve(points, l, m);
    QPair<QPair<long long, long long>, long long> q2 = solve(points, m+1, h);

    QPair<QPair<long long, long long>, long long> q;
    if(q1.second <= q2.second)
        q = q1;
    else
        q = q2;


    //中间两侧的点处理
    QPair<point, long long> *temp = new QPair<point, long long>[h - l + 3];
    int p = 0;
    for(int i = l; i <= h; i++)
        if((points_num[i].first.x - points[m].x) * (points_num[i].first.x - points[m].x) < q.second)
            temp[p++] = points_num[i];

    for(int i = 0; i < p; i++)
        for(int j = i+1; j < std::min(i+7, p); j++)
        {
            if((temp[j].first.y - temp[i].first.y) * (temp[j].first.y - temp[i].first.y) >= q.second)
                break;
            else
            {
                long long d0 = distance_square(temp[i].first, temp[j].first);
                if(d0 < q.second)
                    q = QPair(QPair(temp[i].second, temp[j].second), d0);
            }

        }
    delete[] temp;
    return q;

}

//分治法
QPair<QPair<long long, long long>, long long> closest_2()
{
    quickSortX(points, 1, amount - 1);
    for(int i = 0; i < amount; i++)
    {
        points_num[i].first = points[i];
        points_num[i].second = i;
    }

    quickSortY(points_num, 1, amount - 1);

    return solve(points, 0, amount - 1);
}


#endif // METHOD_H
