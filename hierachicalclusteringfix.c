#include<stdio.h>
#include<math.h>

main(void)
{

    int i,j,k,l,b,a,ranking[200][200],iterasi,loop,newmax,newmin,cl,iterasicl;
    float I[200][200],c[200][20],jarak[200],rank[200],jumlah[200],mean1[200][200],mean2[200][200],mean3[200][200], mean[200][200],kelas[200],kelastesting[200];
    float varian[200];
    cl=2;

    freopen("task1.txt","r",stdin);//if You want to notepad , with name input.txt
    for( int i = 1 ; i <=155; i++ )
    {
        for(j=1; j<=19; j++)
        {
            scanf("%f", &I[i][j]);
        }
        scanf("%f",&kelas[i]);
    }

    //Data Baru yang sudah diNormalisasi Min-Max(0-1)
    //Data Learning
    newmax=1;
    newmin=0;
    for(i=1; i<=155; i++)
    {
        I[i][1]=((I[i][1]-7)*(newmax-newmin))/((78-7)+newmin);
        I[i][14]=((I[i][14]-1)*(newmax-newmin))/((8-1)+newmin);
        I[i][15]=((I[i][15]-26)*(newmax-newmin))/((295-26)+newmin);
        I[i][16]=((I[i][16]-14)*(newmax-newmin))/((648-14)+newmin);
        I[i][17]=((I[i][17]-3)*(newmax-newmin))/((5-3)+newmin);
        I[i][18]=((I[i][18]-0)*(newmax-newmin))/((100-0)+newmin);
        //printf("%d = %f %f %f %f %f %f\n",i,Age[i],Bilir[i],Alk[i],Sgot[i],Albumin[i],Protime[i]);
    }

    for(i=1; i<=cl; i++)
    {
        for(j=1; j<=19; j++)
        {
            c[i][j]=rand()%100/99.1938129;
            //printf("c[%d][%d]= %f\n",i,j,c[i][j]);
        }
    }

    loop=10;
    for(iterasi=1; iterasi<=loop; iterasi++)
    {

        for(i=1; i<=cl; i++)
        {
            jumlah[i]=0;
            for(j=1; j<=19; j++)
            {
                mean[i][j]=0;
            }
        }


        printf("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\");
        printf("\niterasi = %d\n\n",iterasi);
    for(i=1; i<=155; i++)
    {
        for(j=1; j<=cl; j++) //CLuster
        {
            jarak[j]=0;
            for(k=1; k<=19; k++) //Penjumlahan jarak
            {
                jarak[j]=jarak[j]+pow(I[i][k]-c[j][k],2);
            }
            jarak[j]=sqrt(jarak[j]);
            //printf("jarak[%d][%d]=%f\n",i,j,jarak[j]);
        }
         for(j=1; j<=cl; j++)
            {
                rank[j]=1;
                for(b=1; b<=cl; b++)
                    {
                        if(jarak[j]>jarak[b])
                        {
                            rank[j]++;
                        }
                    }
            }
            //printf("Nilai Ujian\t Rangking\n");

        for(j=1; j<=cl; j++)
        //printf("%f\t\t %f\n",jarak[j], rank[j]);

        for(j=1; j<=cl; j++)
        {
            for(k=1; k<=cl; k++)
            {
                if(rank[j]==1 && j==k)
                {
                    jumlah[j]=jumlah[j]+1;
                    ranking[i][j]=j;
                }
                else if(rank[j]!=1)
                {
                    ranking[i][j]=0;
                }
            }
        }

    }

    //printf("\n\n");
    for(i=1; i<=cl; i++)
    {
        //printf("jumlah[%d] = %f\n",i,jumlah[i]);
    }

    for(i=1; i<=155; i++)
    {
        //printf("i= %d   ",i);
        for(j=1; j<=cl; j++)
        {
            for(k=1; k<=cl; k++)
            {
                if(ranking[i][j]==k)
                {
                    kelastesting[i]=ranking[i][j];
                    //printf("class[%d] = %f\n",i,kelastesting[i]);
                    mean[ranking[i][j]][1]=mean[ranking[i][j]][1]+I[i][1];
                    mean[ranking[i][j]][2]=mean[ranking[i][j]][2]+I[i][2];
                    mean[ranking[i][j]][3]=mean[ranking[i][j]][3]+I[i][3];
                    mean[ranking[i][j]][4]=mean[ranking[i][j]][4]+I[i][4];
                    mean[ranking[i][j]][5]=mean[ranking[i][j]][5]+I[i][5];
                    mean[ranking[i][j]][6]=mean[ranking[i][j]][6]+I[i][6];
                    mean[ranking[i][j]][7]=mean[ranking[i][j]][7]+I[i][7];
                    mean[ranking[i][j]][8]=mean[ranking[i][j]][8]+I[i][8];
                    mean[ranking[i][j]][9]=mean[ranking[i][j]][9]+I[i][9];
                    mean[ranking[i][j]][10]=mean[ranking[i][j]][10]+I[i][10];
                    mean[ranking[i][j]][11]=mean[ranking[i][j]][11]+I[i][11];
                    mean[ranking[i][j]][12]=mean[ranking[i][j]][12]+I[i][12];
                    mean[ranking[i][j]][13]=mean[ranking[i][j]][13]+I[i][13];
                    mean[ranking[i][j]][14]=mean[ranking[i][j]][14]+I[i][14];
                    mean[ranking[i][j]][15]=mean[ranking[i][j]][15]+I[i][15];
                    mean[ranking[i][j]][16]=mean[ranking[i][j]][16]+I[i][16];
                    mean[ranking[i][j]][17]=mean[ranking[i][j]][17]+I[i][17];
                    mean[ranking[i][j]][18]=mean[ranking[i][j]][18]+I[i][18];
                    mean[ranking[i][j]][19]=mean[ranking[i][j]][19]+I[i][19];
                }
            }
        }
    }

    //printf("\n\n");
    for(i=1; i<=cl; i++)
    {
        for(j=1; j<=19; j++)
        {
            //printf("mean[%d][%d] = %f\n",i,j,mean[i][j]);
        }
    }

    //printf("\n\n");
    for(i=1; i<=cl; i++)
    {
        for(k=1; k<=cl; k++)
        {
            if(i==k)
            {
                for(j=1; j<=19; j++)
                {
                    if(jumlah[i]==0)
                    {
                        c[i][j]=0;
                    }
                    else if(jumlah[i]!=0)
                    {
                        c[i][j]=mean[i][j]/jumlah[i];
                    }
                    //printf("c[%d][%d] = %f\n",i,j,c[i][j]);
                }
            }
        }

    }

        if(iterasi!=1)
        {
            for(i=1; i<=19; i++)
            {
                c[(iterasi*2)-1][i]=c[1][i];
                c[iterasi*2][i]=c[2][i];
                printf("c[%d][%d]= %f\n",(iterasi*2)-1,i,c[(iterasi*2)-1][i]);
                printf("c[%d][%d]= %f\n",(iterasi*2),i,c[iterasi*2][i]);
            }
        }
    }

    for(i=1; i<=20; i++)
    {
        for(j=1; j<=20; j++)
        {
            printf("c[%d][%d] = %f\n",i,j,c[i][j]);
        }
    }

    /*
    //HIRARKI CLUSTERING
    //Menghitung Jarak
    float d[25][25];
    float distance[425];
    k=1;
    for(i=1; i<=20; i++)
    {
        for(j=1; j<=20; j++)
        {
            if(i<=j)
            {
                d[i][j]=0;
            }
            else
            {
                d[i][j]=0;
                for(l=1; l<=19; l++)
                {
                    d[i][j]=d[i][j]+pow((c[i][l]-c[j][l]),2);
                }
                d[i][j]= sqrt(d[i][j]);
                distance[k++]=d[i][j];
                printf("d[%d][%d] = %f\n",i,j,d[i][j]);
            }

        }
    }

    float peringkat[25][25];
    int e;
    for(j=1; j<=20; j++)
            {
                for(k=1; k<=20; k++)
                {
                    peringkat[j][k]=1;
                    for(b=1; b<=20; b++)
                        {
                            for(e=1; e<=20; e++)
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

        for(j=1; j<=20; j++)
        {
            for(k=1; k<=20; k++)
            {
                printf("d[%d][%d] = %f\t\t %f\n",j,k,d[j][k], peringkat[j][k]);
            }
        }

    printf("\n");
    for(i=1; i<=20; i++)
    {
        for(j=1; j<=19; j++) //attribute
        {
            printf("d[%d][%d] = %f\n",i,j,d[i][j]);
        }
    }

    */

    //////MASUK KEPROSES HIRARKI CLUSTERING////////////////////////////
    int iterate,z,looping,matriksnew[25][25];
    float dd[25][25],cluster[25][25];

    printf("\n");
    printf("//////////////MASUK KE HIRARKI CLUSTERING!!///////////////////////");

    for(i=1; i<=20; i++)
    {
        for(j=1; j<=20; j++)
        {
            dd[i][j]=0;
            if(i>j)
            {
                for(k=1; k<=19; k++) //Attribut
                {
                   dd[i][j]=dd[i][j]+pow((c[i][k]-c[j][k]),2);
                }
                dd[i][j]=sqrt(dd[i][j]);
                printf("d[%d][%d] = %f\n",i,j,dd[i][j]);
            }
            else
            {
                dd[i][j]=10000;
                printf("d[%d][%d] = %f\n",i,j,dd[i][j]);
            }
        }
    }

    looping=16;
    for(iterate=1; iterate<=looping; iterate++)
    {
        printf("\n\n\\\\\\\\\\\\%d \\\\\\\\\\\\\\\\\\\\\\\\\\ \n\n",iterate);
    float peranking[25][25];
    int e,b;
    for(j=1; j<=20; j++)
            {
                for(k=1; k<=20; k++)
                {
                    peranking[j][k]=1;
                    for(b=1; b<=20; b++)
                        {
                            for(e=1; e<=20; e++)
                            {
                                {
                                    if(dd[j][k]>dd[b][e])
                                    {
                                        peranking[j][k]++;
                                    }
                                }
                            }
                        }
                }
            }
            printf("Nilai Ujian\t Rangking\n");

        for(j=1; j<=20; j++)
        {
            for(k=1; k<=20; k++)
            {
                printf("dd[%d][%d] = %f\t\t %f\n",j,k,dd[j][k], peranking[j][k]);
            }
        }

    //Menyimpan centroid berapa saja, yg satu cluster
    int y;
    y=1;
        for(i=1; i<=20; i++)
        {
            for(j=1; j<=20; j++)
            {
                if(peranking[i][j]==1)
                {
                    //printf("\nd[%d][%d] = %f\n",i,j,d[i][j]);
                    matriksnew[iterate][1]=i;
                    printf("\nmatriksnew[%d][2] = %f\n",iterate,matriksnew[iterate][1]);
                    matriksnew[iterate][2]=j;
                    printf("matriksnew[%d][2] = %f\n\n",iterate,matriksnew[iterate][2]);
                }
            }
        }

    //Mengnolkan sisi kanan matriks
    printf("\n");
    for(i=1; i<=20; i++)
    {
        for(j=1; j<=20; j++)
        {
            if(dd[i][j]==10000)
            {
                dd[i][j]=0;

            }
            printf("dd[%d][%d] = %f\n",i,j,dd[i][j]);
        }
    }

    for(i=1; i<=20; i++)
    {
        for(j=1; j<=20; j++)
        {
            if(peranking[i][j]==1)
            {
                for(k=1; k<=20; k++)
                {
                        if(dd[i][k]>=dd[j][k]) //complete linkage
                        {
                            dd[k][i]=dd[i][k]; //ditaruh di kolom terakhir
                        }

                        else
                        {
                            dd[k][i]=dd[j][k];
                        }
                        dd[j][k]=0;
                        dd[k][j]=0;
                        dd[i][k]=0;
                }
            }
        }
    }

    printf("\n");
    for(i=1; i<=20; i++)
    {
        for(j=1; j<=20; j++)
        {
            printf("dd[%d][%d] = %f\n",i,j,dd[i][j]);
        }
    }

    for(i=1; i<=20; i++)
    {
        for(j=1; j<=20; j++)
        {
            if(dd[i][j]==0)
            {
                dd[i][j]=10000;
            }
        }
    }

    } //PENUTUP ITERASI

    printf("\n");
    for(i=1; i<=looping; i++)
    {
        for(j=1; j<=2; j++) //2 alamat kolom dan baris terkecil saat proses complete linkage
        {
            printf("matriksnew[%d][%d] = %d\n",i,j,matriksnew[i][j]);
        }
    }

    float att[25][25];
    int m,one,two;
    one=1;
    two=2;
    m=2;
    att[1][1]=matriksnew[1][1];
    att[1][2]=matriksnew[1][2];
    printf("\n");
    for(i=1; i<=looping-1; i++)
    {
        //for(j=1; j<=2; j++)
        //{
            for(k=2; k<=looping; k++)
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
                            att[i][m++]=matriksnew[k][2];
                        }
                        else if(two==2)
                        {
                            m++;
                            att[i][m++]=matriksnew[k][1];
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

    for(i=1; i<=looping; i++)
    {
        for(j=1; j<=20; j++)
        {
            printf("att[%d][%d] = %f\n",i,j,att[i][j]);
        }
    }


}
