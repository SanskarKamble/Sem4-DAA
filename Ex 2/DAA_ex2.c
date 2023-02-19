#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int limit = 100000;
const int block = 100;

void merge (long arr[],long l,long m,long r) {

    long i = 0, j = 0, k = l;
    long n1 = m - l + 1;
    long n2 = r - m;
    long L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j]; 
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
  
void mergeSort (long arr[],long l,long r) {
    if (l<r) {
        long m = l+(r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void merge_sort (FILE *f) {
	FILE *fp;
	fp = fopen("daa_2_merge_sort.txt", "w");
    	fprintf(fp,"Block Size\tTime Taken\n");
	int size = 0;
	for (int times = 0; times<limit/block; times++) {
		size+=block;
		long arr [size];
		for (int i = 0; i<size; ++i)
			fscanf(f,"%d",&arr[i]);
		// now our array is ready, we perform merge sort
		clock_t t;
		t = clock();
		mergeSort(arr, 0, size-1);
		t = clock()-t;
	    	double time_taken = ((double)t)/CLOCKS_PER_SEC;
	    	// storing the result in a file
	    	fprintf(fp,"%d\t%lf\n",size,time_taken);
    	}
	fclose(fp);
}

long partition (long arr[],long low,long high) 
{
    long pivot = arr[high]; // pivot
    long i = low-1;
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            long temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    long temp = arr[i+1];
    arr[high] = arr[i+1];
    arr[i+1] = temp;
    return i+1;
}

void quickSort (long arr[],long low,long high) 
{
    if (low < high) {
        long pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void quick_sort (FILE *f) {
	FILE *fp;
	fp = fopen("daa_2_quick_sort.txt", "w");
	fprintf(fp,"Block Size\tTime Taken\n");
	int size = 0;
	for (int times = 0; times<limit/block; times++) {
		size+=block;
		long arr [size];
		for (int i = 0; i<size; ++i)
			fscanf(f,"%d",&arr[i]);
		// now our array is ready, we perform quick sort
		clock_t t;
		t = clock();
		quickSort(arr, 0, size-1);
	    	t = clock()-t;
	    	double time_taken = ((double)t)/CLOCKS_PER_SEC;
	    	// storing the result in a file
	    	fprintf(fp,"%d\t%lf\n",size,time_taken);
	}
	fclose(fp);
}

int main () {

	// generating 1,00,000 integers and storing them in a file
	FILE *f;
	f = fopen("daa_2_random_integers.txt", "w");
	for (int i = 0; i<limit; ++i)
		fprintf(f,"%d\n",rand());

	// merge sort
	merge_sort(f);

	// quick sort
	quick_sort(f);

	fclose(f);

	return 0;
}
