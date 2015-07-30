template<class T>
bool lexicographicallySmaller(vector<T> a,vector<T> b)
{
	int n = a.size(),m = b.size();
	int i;
	for(i=0;i<n && i<m;i++)
		if(a[i]<b[i])return 1;
		else if(b[i]<a[i])return 0;
	return (i==n && i< m);
}

