#include<iostream>
using namespace std;
struct activity
{
    int start;
    int finish;
};
void sorting(struct activity data[],int n)
{
    int i,j;
    struct activity temp;
    for(i = 0;i < n;i++)
    {
        for(j = i+1;j < n;j++)
        {
            if(data[i].finish > data[j].finish)
            {
                temp = data[i];
                data[i] = data[j];
                data[j] = temp;
            }
        }
    }
}
void print(struct activity data[],int n)
{
    for(int i = 0;i < n;i++)
    {
        cout << data[i].start << " " << data[i].finish << "\n";
    }
}
int max_activity(struct activity data[],int n)
{
    int i = 0,j,result = 1;
    cout << data[i].start << " " << data[i].finish;
    for(j = 1;j < n;j++)
    {
        if(data[i].finish <= data[j].start)
        {
            cout << "\n" << data[j].start << " " << data[j].finish;
            result++;
            i = j;
        }
    }
    return result;
}
int main()
{
    struct activity data[100];
    int i,n;
    cout << "Input the total number of activities: ";
    cin >> n;
    for(i = 0;i < n;i++)
    {
        cin >> data[i].start >> data[i].finish;
    }
    sorting(data,n);
    int result = max_activity(data,n);
    cout << "\nMax activities : " << result;
    return 0;
}
