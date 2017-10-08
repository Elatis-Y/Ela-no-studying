#include<iostream>
using namespace std;
int a[100005],T[100005];
unsigned long long ans=0;
void mymerge(int left,int mid,int right)
{
    int l=left,r=mid+1,k=left;
    {
        while(l<=mid&&r<=right)
        {
            if(a[l]>a[r])
            {
                T[k++]=a[r++];
                ans+=mid-l+1;
            }
            else
            {
                T[k++]=a[l++];
            }
        }
        while(l<=mid)
        {
            T[k++]=a[l++];
        }
        while(r<=right)
        {
            T[k++]=a[r++];
        }
        for(int i=left;i<=right;++i)
        {
            a[i]=T[i];
        }
    }
}
void mergesort(int left,int right)
{
    if(left<right)
    {
        int mid=(right+left)/2;
        mergesort(left,mid);
        mergesort(mid+1,right);
        mymerge(left,mid,right);
    }
}
int main()
{
    int N;
    cin>>N;
    for(int i=1;i<=N;++i) cin>>a[i];
    mergesort(1,N);
    cout<<ans<<endl;
}
