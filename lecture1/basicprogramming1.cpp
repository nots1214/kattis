#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<vector>
#include<numeric>

using namespace std;


int main() {
	int N, t;
	cin >> N >> t;
	int j = 0;
	int k = 0;
	long long int sum=0;
	vector<int> A(N);
	//vector<int> B(N);
	vector<int> C(N);
	vector<int> D(3);
	vector<int> E(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}


	switch (t) {
	case 1:
		printf("7");
		break;
	case 2:
		if (A[0] > A[1])
			printf("Bigger");
		else if (A[0] == A[1])
			printf("Equal");
		else
			printf("Smaller");
		break;
	case 3:
		D[0] = A[0];
		D[1] = A[1];
		D[2] = A[2];
		sort(D.begin(), D.end());
		printf("%d", D[1]);
		break;
	case 4:
		//printf("%d", (long long int)accumulate(A.begin(), A.end(), 0));
		for (int i = 0; i < N; i++) {
			sum += A[i];
		}
		printf("%lld", sum);
		break;
	case 5:
		for (int i = 0; i < N; i++) {
			if (A[i] % 2 == 0)
				//B[j++] = A[i];
				sum += A[i];
		}
		//printf("%d", accumulate(B.begin(), B.end(), 0));
		printf("%lld", sum);
		break;
	case 6:
		for (int i = 0; i < N; i++) {
			C[i] = A[i] % 26;
		}
		for(int i=0;i<C.size();i++)
		{
			printf("%c", C[i]+'a');
		}
		break;
	case 7:
		k = 0;
		int size = A.size();
		while (1)
		{
			if (A[k] >= size)
			{
				printf("Out");
				break;
			}
			else if (A[k] == size - 1) {
				printf("Done");
				break;
			}
			//else if (A[k] == 0)
			//{
			//	printf("Cyclic");
			//	break;
			//}
			else if (E[k] == 1)
			{
				printf("Cyclic");
				break;
			}
			else {
				E[k]=1;
				k = A[k];
			}
			
		}
		break;

	}

	

	return 0;
}

