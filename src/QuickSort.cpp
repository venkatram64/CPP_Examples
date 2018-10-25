#include <iostream>

using namespace std;

class QuickSort{
  public:
    QuickSort(){}

    void quickSort(int array[], int left, int right){
      if(left >= right){
        return;
      }
      //finding the pivot
      int pivot = array[(left + right)/2];
      int index = partition(array, left, right, pivot);
      //index will become partitioned array boundary of end index
      quickSort(array, left, index - 1);
      //index will become partitioned array boundary of starting index
      quickSort(array, index, right);
    }


    int partition(int array[], int left, int right, int pivot){

      while(left <= right){
        while(array[left] < pivot){
          left++;
        }
        while(array[right] > pivot){
          right--;
        }
        if(left <= right){
          swap(array, left, right);
          left++;
          right--;
        }
      }
      return left;
    }

    void swap(int array[], int left, int right){

      if(array[left] > array[right]){
        int temp = array[left];
        array[left] = array[right];
        array[right] = temp;
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
  QuickSort qs;
  qs.print(array, size);
  cout<<"After sorting "<<endl;
  qs.quickSort(array, 0, size - 1);
  qs.print(array, size);

}
