#include <iostream>

using namespace std;

class MergeSort{
  public: 
    MergeSort(){}
    /* l is for left index and r is right index of the 
      sub-array of array to be sorted 
    */
    void mergeSort(int array[], int l, int r){

      if(l < r){
        //same as (l + r)/2, but avoids the overflow for large left and right
        int m = l + (r -l)/2;
        //sort first and second halves
        mergeSort(array, l, m); //upto middle
        mergeSort(array, m+1, r);//middle to right

        merge(array, l, m, r);
      }

    }

    // Merges two subarrays of array[]. 
    // First subarray is array[l..m] 
    // Second subarray is array[m+1..r] 

    void merge(int array[], int l, int m, int r){
      int i,j,k;
      int n1 = m - l + 1;
      int n2 = r - m;
      //create temp arrays
      int left[n1], right[n2];

      //copy data to temp array left[] and right[]
      for(i = 0; i < n1; i++ ){
        left[i] = array[l + i];
      }

      for(j = 0; j < n2; j++ ){
        right[j] = array[m + 1 + j];
      }

      /* Merge the temp arrays back into array[l..r]*/
      i = 0; // Initial index of first subarray 
      j = 0; // Initial index of second subarray 
      k = l; // Initial index of merged subarray 

      while(i < n1 && j < n2){
        if(left[i] <= right[j]){
          array[k] = left[i];
          i++;
        }else{
          array[k] = right[j];
          j++;
        }
        k++;
      }

      /* Copy the remaining elements of left[], if there 
       are any */

       while(i < n1){
         array[k] = left[i];
         i++;
         k++;
       }

       /* Copy the remaining elements of right[], if there 
       are any */
       while(j < n2){
         array[k] = right[j];
         j++;
         k++;
       }

    } 

    //print method
    void print(int array[], int size){
      for(int i = 0; i < size; i++){
        cout<<array[i] << "  ";
      }
      cout<<endl;
    }
};


int main(){

  int array[] = {17,41,5,22,54,6,29,3,13};
  int size = sizeof(array)/sizeof(array[0]);
  cout<<size<<endl;
  MergeSort ms;
  ms.print(array, size);
  cout<<"After sorting "<<endl;
  ms.mergeSort(array, 0, size - 1);
  ms.print(array, size);
  return 0;
}
