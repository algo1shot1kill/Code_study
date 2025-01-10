/*
* Absolute Permutation
*
*
* https://www.hackerrank.com/challenges/absolute-permutation/problem?isFullScreen=true
*
*/

vector<int> absolutePermutation(int n, int k) {
    vector<int> ret(n + 1);

    for (int i = 1; i <= n; i++)
    {
        if (ret[i] != 0)
            continue;

        if (i - k > 0 && ret[i - k] == 0)
        {
            ret[i] = i - k;
            ret[i - k] = i;
        }
        else if (i + k <= n && ret[i + k] == 0)
        {
            ret[i] = i + k;
            ret[i + k] = i;
        }
        else
        {
            return { -1 };
        }
    }

    return { ret.begin() + 1, ret.end() };
}



/*
vector<int> absolutePermutation(int n, int k) {
    vector<int> ret;


    if(k == 0)
    {
        ret.resize(n);
        iota(ret.begin(),ret.end(),1);
        return ret;
    }

    if(n%2)
    {
        return vector<int>{-1};
    }

//여기서 실수함
    if((n/k)%2)
    {
        return vector<int>{-1};
    }

    int t = n/(2*k);
    for(int i = 0; i< t; i++)
    {
        for(int j = 1; j<=k;j++)
        {
            ret.push_back(2*k*i + k +j);
        }
        for(int j = 1; j<=k;j++)
        {
            ret.push_back(2*k*i + j);
        }
    }

    return ret;
}

 */