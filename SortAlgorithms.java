import java.util.Scanner;

class SortAlgorithms {

    public static void mergeSort(int[] sequence, int length) {

        if (length <= 1) {
            return;
        }

        int i, middle = length / 2;
        int[] leftPartition = new int[middle];
        int[] rightPartition = new int[length - middle];

        for (i = 0; i < middle; i++) {
            leftPartition[i] = sequence[i];
        }

        for (i = middle; i < length; i++) {
            rightPartition[i - middle] = sequence[i];
        }

        mergeSort(leftPartition, middle);
        mergeSort(rightPartition, length - middle);

        merge(sequence, leftPartition, rightPartition, middle, length - middle);
    }

    public static void merge(int[] sequence, int[] leftPartition, int[] rightPartition, int leftPartitionLength,
            int rightPartitionLength) {

        int i = 0, j = 0, count = 0;

        while (i < leftPartitionLength && j < rightPartitionLength) {
            if (leftPartition[i] <= rightPartition[j]) {
                sequence[count] = leftPartition[i++];
            } else {
                sequence[count] = rightPartition[j++];
            }
            count++;
        }

        while (i < leftPartitionLength) {
            sequence[count] = leftPartition[i++];
            count++;
        }

        while (j < rightPartitionLength) {
            sequence[count] = rightPartition[j++];
            count++;
        }
    }

    public static int[] quickSort(int[] sequence, int start, int length) {

        if (start >= length) {
            return sequence;
        }

        int p = sequence[length], left = start, right = length - 1, swap;

        while (left <= right) {

            while (left <= right && sequence[left] <= p) {
                left++;
                ;
            }

            while (left <= right && sequence[right] >= p) {
                right++;
            }

            if (left < right) {
                swap = sequence[left];
                sequence[left] = sequence[right];
                sequence[right] = swap;

            }
        }

        swap = sequence[left];
        sequence[left] = sequence[length];
        sequence[length] = swap;

        quickSort(sequence, start, left - 1);
        quickSort(sequence, left + 1, length);
        return sequence;
    }

    public static class Heap {

        int[] sequence = new int[100000];
        int size = 1;

        Heap() {
        }

        public void insert(int num) {

            sequence[size] = num;

            upHeap();

            size++;
        }

        public void upHeap() {

            int place = size - 1;
            int swap;

            while (place > 1) {

                if (sequence[place / 2] > sequence[place]) {

                    swap = sequence[place];
                    sequence[place] = sequence[place / 2];
                    sequence[place / 2] = swap;
                }
                place = place / 2;
            }

        }

        public int removeMin() {

            int num = sequence[1];

            size--;

            sequence[1] = sequence[size];

            downHeap(1);

            return num;
        }

        public void downHeap(int position) {

            int left = position * 2, right = position * 2 + 1, swap;

            if (left < size && sequence[position] > sequence[left] && sequence[left] <= sequence[right]) {

                swap = sequence[position];
                sequence[position] = sequence[left];
                sequence[left] = swap;

                downHeap(left);

            }

            if (right < size && sequence[position] > sequence[right] && sequence[right] <= sequence[left]) {

                swap = sequence[position];
                sequence[position] = sequence[right];
                sequence[right] = swap;

                downHeap(right);
            }

        }

        public int[] heapSort() {

            int[] sortedArray = new int[100000];
            int length = size;

            for (int i = 0; i < length; i++) {
                sortedArray[i] = removeMin();
            }

            return sortedArray;

        }
    }

    public static void main(String[] args) {

        Scanner scnr = new Scanner(System.in);
        Heap heap = new Heap();

        int temp, i;

        System.out.println("Please enter the length of the sequence(Max length 100000)");
        int length = scnr.nextInt();

        int[] sequence = new int[length];
        int[] sequence3 = new int[length];

        System.out.println("Please enter the integers of the sequence seperated by a space");

        for (i = 0; i < length; i++) {
            temp = scnr.nextInt();
            sequence[i] = temp;
            heap.insert(temp);
        }
        int[] sequence2 = sequence;

        mergeSort(sequence, length);
        quickSort(sequence2, 0, length - 1);
        sequence3 = heap.heapSort();

        System.out.println("Merge sort result:");
        for (i = 0; i < length; i++) {
            System.out.print(sequence[i] + " ");
        }
        System.out.println();

        System.out.println("Quick sort result:");
        for (i = 0; i < length; i++) {
            System.out.print(sequence2[i] + " ");
        }
        System.out.println();

        System.out.println("Heap sort result:");
        for (i = 0; i < length; i++) {
            System.out.print(sequence3[i] + " ");
        }
    }
}
