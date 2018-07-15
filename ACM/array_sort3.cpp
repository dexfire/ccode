int partition(int[] a, int low, int high) {
        int i = low + 1;
        int j = high + 1;

        //p为切分元素
        int p = a[low];
        while (true) {
            //从数组中的第二个元素开始寻找第一个大于等于切分元素的数组元素，若找到则i为其索引
            while (a[++i] < p) {
                if (i == high) {
                    break;
                }
            }
            //此时i为从数组首部开始第一个大于等于切分元素的数组元素的索引，若没有找到则为high
            
            //从数组末元素开始寻找第一个小于等于切分元素的数组元素，若找到则j为其索引
            while (a[--j] > p) {
                if (j == low) {
                    break;
                }
            }
            //此时j为从数组末开始第一个小于等于切分元素的数组元素的索引，若没有找到则为low
            
            if (i >= j) {
                break;
            }
            exchange(a, i, j);
        }
        exchange(a, low, j);
        return j;
    }