/*
나를 포함해서 만들 수 있는 가장 큰 직사각형이 담긴 배열
-> 만들고 나서 max 값
 */
#include <bits/stdc++.h>

using namespace std;
int main (){
    
    while(true)
    {
        int n;
        cin >> n;
        if(n == 0)
        {
            break;
        }
        vector<long long> height;
        height.push_back(-1);
        for(int i = 0; i<n;i++)
        {
           long long n;
            cin >>n;
           height.push_back(n);
        }
        
        height.push_back(-1);
        /*
        스택에 나보다 작은 애들만 있다. => 만약 스택에 나보다 큰 값이 있다면, 나~걔보다 작은 값 * 걔 높이 가 가장 큰 사각형.
        */
        stack<long long> s;
        long long m = 0;
        for(long long i = 0; i<height.size();i ++)
        {
            while(!s.empty() && height[s.top()] > height[i])
            {
                long long h = height[s.top()];
                s.pop();
                long long r = i;
                long long l = s.top();
                m = max(m,h*(r-l-1));
            }
            s.push(i);
        }
        cout << m<<'\n';
    }
    

    
    return 0;
}


/*

#include <bits/stdc++.h>

using namespace std;
int main (){
    
    while(true)
    {
        int n;
        cin >> n;
        if(n == 0)
        {
            break;
        }
        vector<long long> height(n);
        vector<long long> max_height(n);
        generate(height.begin(),height.end(),[](){
            long long n;
            cin >>n;
            return n;
        });

        *
        스택이 나보다 크면 뺀다. 작으면 넣는다. 비어도 넣는다.
        -> 스택에는 나보다 작은 가장 오른쪽 애가 top이다.
        1) 걔 높이 ~ 내 인덱스까지 사각형
        2) 걔 제외 ~ 내 높이까지 사각형
        중에 큰 게 나를 포함한 가장 큰 사각형
        *
        
        *
        for i,index in height
            wile(not empty and stackTop > i)
            {
                pop
            }
            
            result[index] = max((index-topIndex) * topHeight, (index-topIndex-1) * i )
        
        *
        //height, index
        
        stack<pair<long long,long long>> s;
        
        for(long long i = 0; i< height.size();i++)
        {
            while(!s.empty() && s.top().first > height[i])
            {
                s.pop();
            }
            
            if(s.empty())
            {
                max_height[i] = (i+1)*height[i];
                s.push({height[i],i});
                continue;
            }
            auto [h,index] = s.top();
            max_height[i] = max((i-index+1) * h,(i-index) * height[i] );
            
            if(h < height[i])
            {
                s.push({height[i],i});
            }
        }
        
        for(auto i : max_height)
        {
            cout << ' '<<i;
        }
        cout <<'\n';
        sort(max_height.begin(), max_height.end(),greater<>());
        
        cout << max_height[0];
    }
    

    
    return 0;
}
*/