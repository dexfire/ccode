int partition(int[] a, int low, int high) {
        int i = low + 1;
        int j = high + 1;

        //pΪ�з�Ԫ��
        int p = a[low];
        while (true) {
            //�������еĵڶ���Ԫ�ؿ�ʼѰ�ҵ�һ�����ڵ����з�Ԫ�ص�����Ԫ�أ����ҵ���iΪ������
            while (a[++i] < p) {
                if (i == high) {
                    break;
                }
            }
            //��ʱiΪ�������ײ���ʼ��һ�����ڵ����з�Ԫ�ص�����Ԫ�ص���������û���ҵ���Ϊhigh
            
            //������ĩԪ�ؿ�ʼѰ�ҵ�һ��С�ڵ����з�Ԫ�ص�����Ԫ�أ����ҵ���jΪ������
            while (a[--j] > p) {
                if (j == low) {
                    break;
                }
            }
            //��ʱjΪ������ĩ��ʼ��һ��С�ڵ����з�Ԫ�ص�����Ԫ�ص���������û���ҵ���Ϊlow
            
            if (i >= j) {
                break;
            }
            exchange(a, i, j);
        }
        exchange(a, low, j);
        return j;
    }