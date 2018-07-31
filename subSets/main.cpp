#include <iostream>
#include <vector>
using namespace std;

namespace algorithm1
{
    template<class T>  
    void print(T a[],int mark,int length)    
    {    
        bool allZero=true;    
        int limit=1<<length;    
        for(int i=0;i<length;++i)    
        {    
            if(((1<<i)&mark)!=0)      //mark第i+1位为1，表示取该元素    
            {    
                allZero=false;    
                cout<<a[i]<<" ";    
            }    
        }    
        if(allZero==true)    
        {    
            cout<<"@";    
        }    
        cout<<endl;    
    }  
    template<class T>  
    void subset(T a[],int length)    
    {    
        if(length>31) return;    
        int lowFlag=0;                  //对应000...000    
        int highFlag=(1<<length)-1;       //对应111...111    
        for(int i=lowFlag;i<=highFlag;++i)    
        {    
            print(a,i,length);    
        }    
    }  
}

namespace algorithm1Plus
{  
    template<class T>  
    void subset(T a[], vector<vector<T>>& results, int length)    
    {    
        if(length>31) return;    
        int lowFlag=0;                  //对应000...000    
        int highFlag=(1<<length)-1;       //对应111...111    
        vector<T> temp;
        for(int i=lowFlag;i<=highFlag;++i)    
        {    
            temp.clear();
            for( int j = 0; j < length; ++j )
            {
                if( ((1<<j) & i) != 0 )
                {
                    temp.push_back( a[j] );
                }
            }
            results.push_back( temp );
        }    
    }  
}


namespace algorithm2
{
    int cnt = 0;
    template<class T>
    void print(T a[],bool marks[],int length)    
    {    
        bool allFalse=true;    
        for(int i=0;i<length;++i)    
        {    
            if(marks[i]==true)    
            {    
                allFalse=false;    
                cout<<a[i]<<" ";    
            }    
        }    
        if(allFalse==true)    
        {    
            cout<<"@";    
        }    
        cout<<endl;  
    }  


    //n is the index, so it is the length - 1
    template<class T>  
    void subset(T a[],bool marks[],vector<vector<T>>& results,int m,int n,int length)    
    {    
        if(m>n)    
        {    
            //cout<<" time: "<<++cnt<<endl;
            vector<T> temp;
            for( int i = 0; i < length; ++i )
            {
                if( marks[i] )
                {
                    temp.push_back( a[i] );
                }
            }
            results.push_back( temp );
        }    
        else    
        {    
            marks[m]=true;    
            subset(a,marks,results,m+1,n,length);   
            marks[m]=false;    
            subset(a,marks,results,m+1,n,length);   
        }  
    } 
}


void main()
{
    const int dataLength = 5;
    int data[dataLength];
    for( int i = 0; i < dataLength; ++i )
    {
        data[i] = i;
    }
    vector<vector<int>> subSets;
    algorithm1::subset<int>( data, dataLength );
    
    cout<<"algorithm1Plus"<<endl;
    algorithm1Plus::subset<int>( data,subSets, dataLength );
    for( auto& subdata: subSets )
    {
        for( auto data1 : subdata )
        {
            cout << data1 << " ";
        }
        cout<< endl;
    }


    std::cout <<  " algorithm2 "<<endl;
    bool marks[dataLength];
    vector<vector<int>> subSetResult;
    algorithm2::subset( data,marks,subSetResult,0,dataLength - 1, dataLength );
    for( auto& subdata: subSetResult )
    {
        for( auto data1 : subdata )
        {
            cout << data1 << " ";
        }
        cout<< endl;
    }
    system("pause");
}




 