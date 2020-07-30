#include <iostream>
using namespace std;

#define MAX 5000000     // ��������ǿ�
#define SENTINEL 2000000000     // ��ʼ�Ѥ������礭����

int L[MAX/2+2], R[MAX/2+2];
int cnt;        // ��Ӳ��

void merge(int A[], int left, int mid, int right) {        // mergeSort�ˤ�ä�����줿�����ȺѤߤ���ʬ��������礹��ؿ�
    int n1 = mid - left;        // ��¦��������礭��
    int n2 = right - mid;       // ��¦��������礭�� (right����ʬ���������+1�Υ���ǥå���)
    
    // L[0...n1]��R[0...n2]�ʤ����������
    for (int i = 0; i < n1; ++i) {
        L[i] = A[left + i];
    }
    for (int i = 0; i < n2; ++i) {
        R[i] = A[mid + i];
    }
    L[n1] = SENTINEL;
    R[n2] = SENTINEL;

    // �����ȺѤ���������礹��
    int i = 0, j = 0;
    for (int k = left; k < right; ++k) {
        cnt++;
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
    }
}

void mergeSort(int A[], int left, int right) {      // ����򤽤줾��ȾʬȾʬ��ʬ�䤹��ؿ�
    if (left + 1 < right) {     // ʬ�䤷����ʬ��������ǿ���1�ˤʤ�ޤ�ʬ�䤹��
        int mid = (left + right) / 2;
        mergeSort(A, left, mid);        // ��Ⱦʬ��ʬ��
        mergeSort(A, mid, right);       // ��Ⱦʬ��ʬ��
        merge(A, left, mid, right);     // merge��ʬ�䤷�����������
    }
}

int main() {
    int n, S[MAX];
    cnt = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> S[i];
    }
    mergeSort(S, 0, n);

    for (int i = 0; i < n; ++i) {
        if (i) cout << " ";
        cout << S[i];
    }
    cout << endl;
    
    cout << cnt << endl;

    return 0;
}