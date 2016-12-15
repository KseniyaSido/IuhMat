#include<stdio.h>
#include<stdlib.h>
void inversion(double **A, int N)
{
    double temp;
    int i, j, k;
    double **E = (double**)malloc(sizeof(double *) * N);

    for (i = 0; i < N; i++)
        E[i] = (double*)malloc(sizeof(double) * N);

    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
        {
            if (i == j)
            {
             E[i][j] = 1;
            }
            else
            {
                E[i][j] = 0;
            }
        }
    for (k = 0; k < N; k++)
    {
        temp = A[k][k];

        for (j = 0; j < N; j++)
        {
            A[k][j] /= temp;
            E[k][j] /= temp;
        }

        for (i = k + 1; i < N; i++)
        {
            temp = A[i][k];

            for (j = 0; j < N; j++)
            {
                A[i][j] -= A[k][j] * temp;
                E[i][j] -= E[k][j] * temp;
            }
        }
    }
    for (k = N - 1; k > 0; k--)
    {
        for (i = k - 1; i >= 0; i--)
        {
            temp = A[i][k];

            for (j = 0; j < N; j++)
            {
                A[i][j] -= A[k][j] * temp;
                E[i][j] -= E[k][j] * temp;
            }
        }
    }

    for (i = 0; i < N; i++)
 {

        for (j = 0; j < N; j++)
        {
            A[i][j] = E[i][j];
        }

}

}
int main()
{
    int n, i, j;
    double ** mas;
    double * vect;
    double * vect_fin;
    scanf("%d", &n);
    vect = (double*)malloc(n * sizeof(double));
    vect_fin = (double*)malloc(n * sizeof(double));
    mas = (double**)malloc(n * sizeof(double*));
    for(i = 0; i < n; i++)
    {
        mas[i] = (double*)malloc(n * sizeof(double));
        for(j = 0; j < n; j++)
        {
            scanf("%lf", &mas[i][j]);
        }
    }
	for(i = 0; i < n; i ++)
    {
        scanf("%lf", &vect[i]);
    }
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            printf("%lf ", mas[i][j]);
        }
        printf("\n");
    }
    inversion(mas, n);
    for (i = 0; i < n; i ++)
    {
    	vect_fin[i] = 0;
        for(j = 0; j < n; j++)
        {
            i[vect_fin] += i[mas][j] * j[vect];
        }
    }
    for(i = 0; i < n; i++)
    {
            printf("%lf\n", vect_fin[i]);
    }
    free(mas);
    return 0;
}
