package org.example;

import org.jetbrains.annotations.NotNull;

import java.util.Random;

public class QuickSorts {

    static void swap(int @NotNull [] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    static int partition(int[] arr, int low, int high) {
        // Choosing the pivot
        Random random = new Random();
        int los = random.nextInt(high - low) + low;
        swap(arr, los, high);

        int i = low;

        for (int j = low; j <= high; j++) {

            if (j == high || arr[j] < arr[high]) {

                swap(arr, i, j);
                i++;
            }
        }
        return (i - 1);
    }

    static int partitionRandom(int[] arr, int low, int high) {
        Random random = new Random();
        int los = random.nextInt(high - low) + low;
        swap(arr, los, high);

        int i = low;

        for (int j = low; j <= high; j++) {

            if (j == high || arr[j] < arr[high] ) {

                swap(arr, i, j);
                if(i<arr.length-1){
                    i++;
                }

            }
            //jesli randomowa liczba podzielna przez 2 to traktujemy obiekt rowny pivotowi jako nizszy
            if (arr[j] == arr[high] ) {
                int coinFlip = random.nextInt();
                if (coinFlip % 2 == 0) {

                    swap(arr, i, j);
                    if(i<arr.length-1){
                        i++;
                    }
                }
            }
        }
        return (i - 1);
    }

    static int start, stop;

    static void partitionDutchFlag(int[] arr, int low, int high) {
        start = low - 1;
        stop = high;
        int p = low - 1, q = high;
        int v = arr[high];

        while (true) {

            while (arr[++start] < v) ;

            while (v < arr[--stop])
                if (stop == low)
                    break;

            if (start >= stop)
                break;

            swap(arr, start, stop);

            if (arr[start] == v) {
                p++;
                swap(arr, start, p);
            }

            if (arr[stop] == v) {
                q--;
                swap(arr, q, stop);
            }
        }

        swap(arr, start, high);

        stop = start - 1;
        for (int k = low; k < p; k++, stop--) {
            swap(arr, k, stop);
        }

        start = start + 1;
        for (int k = high - 1; k > q; k--, start++) {
            swap(arr, start, k);
        }
    }

    static void quickSortDutchFlag(int[] arr, int low, int high) {
        if (low < high) {
            start = 0;
            stop = 0;

            partitionDutchFlag(arr, low, high);

            quickSortDutchFlag(arr, low, stop);
            quickSortDutchFlag(arr, start, high);
        }
    }

    static void quickSort(int[] arr, int low, int high) {
        if (low < high) {

            int pi = partition(arr, low, high);

            quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, high);
        }
    }

    static void quickSortRandom(int[] arr, int low, int high) {
        if (low < high) {

            int pi = partitionRandom(arr, low, high);

            quickSortRandom(arr, low, pi - 1);
            quickSortRandom(arr, pi + 1, high);
        }
    }

    // To print sorted array
    public static void printArr(int[] arr) {
        for (int j : arr) {
            System.out.print(j + " ");
        }
        System.out.println(" ");
    }
}

