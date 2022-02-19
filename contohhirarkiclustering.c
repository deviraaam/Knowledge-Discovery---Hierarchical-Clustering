#include<stdio.h>
#include<math.h>

main(void)
{
    int i,j,k,l,iterasi,z,loop,matriksnew[20][20];
    float I[10][10],d[20][20],cluster[20][20];

    I[1][1]=2;  I[1][2]=4;
    I[2][1]=8;  I[2][2]=2;
    I[3][1]=9;  I[3][2]=3;
    I[4][1]=1;  I[4][2]=5;
    I[5][1]=8.5;  I[5][2]=1;

    z=1;

    for(i=1; i<=5; i++)
    {
        for(j=1; j<=5; j++)
        {
            d[i][j]=0;
            if(i>j)
            {
                for(k=1; k<=2; k++) //Attribut
                {
                   d[i][j]=d[i][j]+pow((I[i][k]-I[j][k]),2);
                }
                d[i][j]=sqrt(d[i][j]);
                printf("d[%d][%d] = %f\n",i,j,d[i][j]);
            }
            else
            {
                d[i][j]=10000;
                printf("d[%d][%d] = %f\n",i,j,d[i][j]);
            }
        }
    }

    loop=3;
    for(iterasi=1; iterasi<=loop; iterasi++)
    {
        printf("\n\n\\\\\\\\\\\\%d \\\\\\\\\\\\\\\\\\\\\\\\\\ \n\n",iterasi);
    float peringkat[25][25];
    int e,b;
    for(j=1; j<=5; j++)
            {
                for(k=1; k<=5; k++)
                {
                    peringkat[j][k]=1;
                    for(b=1; b<=5; b++)
                        {
                            for(e=1; e<=5; e++)
                            {
                                {
                                    if(d[j][k]>d[b][e])
                                    {
                                        peringkat[j][k]++;
                                    }
                                }
                            }
                        }
                }
            }
            printf("Nilai Ujian\t Rangking\n");

        for(j=1; j<=5; j++)
        {
            for(k=1; k<=5; k++)
            {
                printf("d[%d][%d] = %f\t\t %f\n",j,k,d[j][k], peringkat[j][k]);
            }
        }

    //Menyimpan centroid berapa saja, yg satu cluster
    int y;
    y=1;
        for(i=1; i<=5; i++)
        {
            for(j=1; j<=5; j++)
            {
                if(peringkat[i][j]==1)
                {
                    //printf("\nd[%d][%d] = %f\n",i,j,d[i][j]);
                    matriksnew[iterasi][1]=i;
                    printf("\nmatriksnew[%d][2] = %f\n",iterasi,matriksnew[iterasi][1]);
                    matriksnew[iterasi][2]=j;
                    printf("matriksnew[%d][2] = %f\n\n",iterasi,matriksnew[iterasi][2]);
                }
            }
        }

    //Mengnolkan sisi kanan matriks
    printf("\n");
    for(i=1; i<=5; i++)
    {
        for(j=1; j<=5; j++)
        {
            if(d[i][j]==10000)
            {
                d[i][j]=0;

            }
            printf("d[%d][%d] = %f\n",i,j,d[i][j]);
        }
    }

    for(i=1; i<=5; i++)
    {
        for(j=1; j<=5; j++)
        {
            if(peringkat[i][j]==1)
            {
                for(k=1; k<=5; k++)
                {
                        if(d[i][k]>=d[j][k]) //complete linkage
                        {
                            d[k][i]=d[i][k]; //ditaruh di kolom terakhir
                        }

                        else
                        {
                            d[k][i]=d[j][k];
                        }
                        d[j][k]=0;
                        d[k][j]=0;
                        d[i][k]=0;
                }
            }
        }
    }

    printf("\n");
    for(i=1; i<=5; i++)
    {
        for(j=1; j<=5; j++)
        {
            printf("d[%d][%d] = %f\n",i,j,d[i][j]);
        }
    }

    for(i=1; i<=5; i++)
    {
        for(j=1; j<=5; j++)
        {
            if(d[i][j]==0)
            {
                d[i][j]=10000;
            }
        }
    }

    } //PENUTUP ITERASI

    printf("\n");
    for(i=1; i<=loop; i++)
    {
        for(j=1; j<=2; j++) //2 alamat kolom dan baris terkecil saat proses complete linkage
        {
            printf("matriksnew[%d][%d] = %d\n",i,j,matriksnew[i][j]);
        }
    }

    float att[20][20];
    /*
    printf("\n");
    for(i=1; i<=2; i++) //Attribute
    {
        att[1][i]=I[matriksnew[1][1]][i]+I[matriksnew[1][2]][i];
        printf("att[1][%d] = %f\n",i,att[1][i]);
    }
    */
    /*
    printf("\n");
    for(i=2; i<=loop; i++)
    {
        for(j=1; j<=2; j++) //2 alamat kolom dan baris terkecil saat proses complete linkage
        {
            if(matriksnew[i][j]!=)
        }
    }
    */
    int m,one,two;
    one=1;
    two=2;
    m=2;
    att[1][1]=matriksnew[1][1];
    att[1][2]=matriksnew[1][2];
    printf("\n");
    for(i=1; i<=loop-1; i++)
    {
        //for(j=1; j<=2; j++)
        //{
            for(k=2; k<=loop; k++)
            {
                //for(l=1; l<=2; l++)
                //{
                    if(matriksnew[i][1]==matriksnew[k][one]||
                       matriksnew[i][1]==matriksnew[k][two]||
                       matriksnew[i][2]==matriksnew[k][one]||
                       matriksnew[i][2]==matriksnew[k][two])
                    {
                        if(one==1)
                        {
                            m++;
                            att[i][m++]=matriksnew[k][1];
                        }
                        else if(two==2)
                        {
                            m++;
                            att[i][m++]=matriksnew[k][2];
                        }
                    }
                    else
                    {
                        att[i][1]=matriksnew[i][1];
                        att[i][2]=matriksnew[i][2];
                    }
                //}
            }
        //}
    }

    for(i=1; i<=loop; i++)
    {
        for(j=1; j<=4; j++)
        {
            printf("att[%d][%d] = %f\n",i,j,att[i][j]);
        }
    }
}
