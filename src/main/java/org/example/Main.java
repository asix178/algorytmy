package org.example;

import org.apache.commons.lang3.time.StopWatch;

import java.util.Random;

import static org.example.QuickSorts.*;

public class Main {
    public static void main(String[] args) {
        StopWatch stopWatch = new StopWatch();
        Random random = new Random();
        int[] arr = new int[10000];
        int N = arr.length;

        for (int j = 0; j < N; j++) {
            arr[j] = random.nextInt(5000000);
        }
        for (int i = 0; i < 3; i++) {
            int[] copy = new int[10000];
            System.arraycopy(arr, 0, copy, 0, 10000);
//            System.out.println("Unsorted:");
//            printArr(copy);
            stopWatch.start();
            if (i == 0) {
                quickSort(copy, 0, N - 1);}
            if (i == 1) {
                quickSortRandom(copy, 0, N - 1);
            }
            if (i == 2) {
                quickSortDutchFlag(copy, 0, N - 1);
            }
            stopWatch.stop();
            System.out.println("Elapsed time[ms]: " + stopWatch.getTime());
            stopWatch.reset();
//            System.out.println("Sorted:");
//            printArr(copy);

        }
//        printArr(arr);
//        System.out.println("Sorted array:");
//        printArr(arr);
    }
}