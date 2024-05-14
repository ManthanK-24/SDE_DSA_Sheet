


int solve(vector<int>& book, int k)
{
  int ans = -1;
   int sum = 0;
  for(auto x:book)sum+=x;
   int low = max(book.begin(),book.end());
   int high = sum;

   while(low<=high)
     {
        int mid = (low+high) >> 1;
       if(isPossible(book,k,mid))
       {
         ans = mid;
         high = mid-1;
       }
       else
         low=mid+1;
     }
  return low;
}

bool isPossible(vector<int>& book, int k,int barrier)
{
     int stud = 1;
     int pages =0;
     for(int i=0;i<book.size();i++)
       {
           if(book[i]>barrier)return false;
           if(book[i] + pages > barrier)
           {
             stud++;
             pages = book[i];
           }
           else
           pages += book[i];
       }
     if(stud>k)return false;
  return true;
}



