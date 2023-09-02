package Array;

public class Sort {
	public static void main(String[] args) {
				
		int[] arr1= {7,4,5,1,3};
		int[] arr2= {9,2,2,2,5,4,3,1,6,7,3,8,0,3};
		
		printArr(arr1);
		bubbleSort(arr1);
		printArr(arr1);
		
		System.out.println();
		
		printArr(arr2);
		bubbleSort(arr2);
		System.out.println("simple bubble sort");
		printArr(arr2);
	}
	public static void bubbleSort(int arr[]) {
		bubbleSort(arr,arr.length);
	}
	
	public static void bubbleSort(int arr[], int n) {
		for(int i=0;i<n-1;i++) {
			boolean swap=false;
			for (int j=0; j<n-i-1; j++) {
	            if (arr[j] > arr[j+1]) {
	            	int temp = arr[j];
	                arr[j] = arr[j+1];
	        	    arr[j+1] = temp;
	        	    swap=true;
	            }
			}
			if(!swap) {
				break;
			}
		}
	}
	public static void printArr(int arr[]) {
		for(int i=0;i<arr.length;i++) {
			System.out.print(arr[i]+" ");
		}
		System.out.println();
	}
}
