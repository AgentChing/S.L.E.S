
#include<stdio.h>
#include<math.h>


void main()
{
 printf("ENTER THE NUMBER OF COEFFICIENTES AND NUMBER OF EQUATIONS\n");
 int row,coloum;
 scanf("%d",&coloum);
 scanf("%d",&row);
 int trow=coloum-1,tcoloum=row;
 int matrix[row][coloum],matrix_cpy[row][coloum],aug_matrix[row][coloum-1],matrix_tran[trow][tcoloum],ATA[trow][trow];
 float solution[trow];

 printf("\n ENTER THE ELEMENTS\n");
 for(int i=0;i<row;i++)
  {
   for(int j=0;j<coloum;j++)
   {
    printf("element %d of equation %d is:-",j+1,i+1);
    scanf("%d",&matrix[i][j]);                                       //here it will scan and initialise the matrix and its copy
    printf("\n");
    matrix_cpy[i][j]=matrix[i][j];
   }
  }



 printf("\n\n THE SYSTEM OF EQUATIONS LOOKS LIKE THIS IN MATIX FORM\n");
for(int i=0;i<row;i++)
  {
   for(int j=0;j<coloum;j++)
   {
    printf("%d\t",matrix[i][j]);                                  //this will print the matrix form of the inputed equations
   }
   printf("\n");
  }

printf("\n\n-----------------------------------------------------------------------------------");
 //now starts the calculating part
for(int j=0;j<coloum;j++)
{
//-------------------------------------------------------------------------
    //first to sort the elements in increasing order of their magnitude

    for(int i=j;i<row;i++)
    {
        for(int k=i+1;k<row;k++)
        {
            if(matrix[i][j]==0&&matrix[k][j]!=0)
            {
                float temp;
                for(int l=j;l<coloum;l++)
                {
                    temp=matrix[i][l];                           //here the elements are sorted
                    matrix[i][l]=matrix[k][l];
                    matrix[k][l]=temp;
                }
            }
            else if(matrix[i][j]==0 && matrix[k][j]==0)
                continue;
        }
    }
//------------------------------------------------------------------------
  for(int i=j+1;i<row;i++)
  {
      for(int k=coloum-1;k>=0;k--)
      {                                                                              //here it will calculate the value of each and every elements
          matrix[i][k]=(matrix[i][k]*matrix[j][j])-(matrix[j][k]*matrix[i][j]);      //of the echelon form.
      }
  }

}
//----------------------------------------------------------------------------------------


 printf("\n\n THE ECHELON FORM OF THE MATRIX IS:-\n");
for(int i=0;i<row;i++)
  {
   for(int j=0;j<coloum;j++)
   {aug_matrix[i][j]=matrix[i][j];
    printf("%d\t",matrix[i][j]);                                  //this will print the echelon form of the matrix
   }
   printf("\n");
  }

//-----------------------------------------------------------------------------------------

printf("\n\n AND THE AUGMENTED MATRIX LOOKS LIKE:-\n");
for(int i=0;i<row;i++)
  {
   for(int j=0;j<coloum-1;j++)
   {
    printf("%d\t",matrix[i][j]);                                  //this will print the echelon form of the AUGMENTED matrix
   }
   printf("\n");
  }

//-----------------------------------------------------------------------------------------
int rank=0,rank_aug=0;

for(int i=0;i<row;i++)
{
    for(int j=0;j<coloum;j++)
    {
        if(matrix[i][j]!=0)
        {rank+=1;
         break;
        }
    }
}
                                                    //calculate rank of the matrix and the augmented matrix
for(int i=0;i<row;i++)
{
    for(int j=0;j<coloum-1;j++)
    {
        if(matrix[i][j]!=0)
        {rank_aug+=1;
         break;
        }
    }
}

printf("\n Rank of matrix is= %d \n\n Rank of Augmented matrix is= %d\n\n",rank,rank_aug);

//-----------------------------------------------------------------------------------------------

int homo=0;
for(int i=0;i<row;i++)
{
    if(matrix[i][coloum-1]!=0)
    {                                          // here if homo=0:homogenius elif homo=1:non-homogenius
        homo=1;
        break;
    }
}

//------------------------------------------------------------------------------------------------
 int soln_type;   // soln_type=0: unique soln;  soln_type=1: infinite soln
 int consistency;
switch(homo)
{
    case 0:{printf("\n HOMOGENEOUS SYSTEM\n");
            if(rank_aug==coloum-1)
                consistency=1;
            }
            break;
    case 1:{printf("\n NON-HOMOGENEOUS SYSTEM\n");
            if(rank_aug==rank)
                consistency=1;
            else
                consistency=0;
           }
}


switch(consistency)
{
    case 0:{printf("\n\n SYSTEM IS INCONSISTENT\n");}
            break;
    case 1:{printf("\n\n SYSTEM IS CONSISTENT\n");
    if(rank==coloum-1)
        printf("\t\t  with UNIQUE SOLUTION");
    else if(rank<coloum-1)
        printf("\t\t  with INFINITELY MANY SOLUTIONS");

    }
}

//-------------------------------------------------------------------------------------------
if(consistency==1){
int non_pivot[coloum],a=0,b=0,column=0,j=0;
for(int i=0;i<row;i++)
{
  for(j;j<coloum-1;)
  {
      if(aug_matrix[i][j]!=0)
      {
          j+=1;break;
      }
      else

      {
          non_pivot[b]=j;b+=1;j+=1;
      }
  }

}
printf("\n\n");
//------------------------------------
if(b==1)
{

for(int i=0;i<(b);i++)                                //printing free variables
    printf("%d ",non_pivot[i]+1);
printf(" NUMBERED VARIABLE IS A FREE VARIABLE");
}
else if(b>1)
{
    for(int i=0;i<(b);i++)                                //printing free variables
    printf("%d ",non_pivot[i]+1);
printf(" NUMBERED VARIABLES ARE FREE VARIABLES");
}
//------------------------------------------------------------------------------------------------------------------

float values[coloum];
for(int i=0;i<coloum-1;i++)
    values[i]=1;

if(b!=0)
{
printf("\n\n ENTER THE VALUES OF FREE VARIABLES:");

for(int i=0;i<b;i++)
{                                                  //accept values of free variables from user.
    printf("\nVARIABLE %d=",non_pivot[i]+1);
    scanf("%f",&values[non_pivot[i]]);
}
}


//---------------------------------------------------------------------------------------------------------------------
float t_value=0;// changed form float to int

for(int i=rank-1;i>=0;i--)
{
    for(int j=0;j<coloum;j++)
    {
        if(matrix[i][j]!=0)
        {
            for(int k=coloum-2;k>j;k--)
            {
                t_value=t_value+(matrix[i][k]*values[k]);
            }                                                               //CALCULATES VALUES OF VARIABLES
            values[j]=(matrix[i][coloum-1]-t_value)/matrix[i][j];
            t_value=0;
            break;
        }
    }
}
for(int i=0;i<coloum-1;i++)
    printf("\nVALUE OF VARIABLE %d= %f",i+1,values[i]);//removed %o.2f
}
printf("\n\n-----------------------------------------------------------------------------------");
//-------------------------------------------------------------------------------------------------------------------------

if(consistency==0)
{
  for(int i=0;i<row;i++)
  {
      for(int j=0;j<coloum-1;j++)
      {                                               //getting trans matrix
          matrix_tran[j][i]=matrix_cpy[i][j];
      }
  }

     //------------------------------------------------------------------------------------

printf("\n");
for(int i=0;i<trow;i++)
{
    for(int k=0;k<trow;k++)
  {
     int value=0;
     for(int j=0;j<tcoloum;j++)
     {
        value=value+(matrix_cpy[j][k]*matrix_tran[i][j]);
     }

    ATA[i][k]=value;                                          //getting trans(A).A
  }

}

  //------------------------------------------------------------------------------------------------------------
  float list[trow];
for(int i=0;i<trow;i++)
{
    float value=0;
    for(int j=0;j<tcoloum;j++)
    {
        value=value+(matrix_tran[i][j]*matrix_cpy[j][coloum-1]);
    }
   list[i]=value;
}

//-------------------------------------------------------------------------------------------------------------------

float newmatrix[trow][trow+1];
for(int i=0;i<trow;i++)
{
    for(int j=0;j<trow+1;j++)
    {
        if(j<trow)                                                             //new matrix
        {
            newmatrix[i][j]=ATA[i][j];
        }
        else
            newmatrix[i][j]=list[i];
    }
}

//-----------------------------------------------------------------------------------------------------------------------


for(int j=0;j<trow+1;j++)
{
//-------------------------------------------------------------------------
    //first to sort the elements in increasing order of their magnitude

    for(int i=j;i<trow;i++)
    {
        for(int k=i+1;k<trow;k++)
        {
            if(newmatrix[i][j]==0&&newmatrix[k][j]!=0)
            {
                float temp;
                for(int l=j;l<trow+1;l++)
                {
                    temp=newmatrix[i][l];                           //here the elements are sorted
                    newmatrix[i][l]=newmatrix[k][l];
                    newmatrix[k][l]=temp;
                }
            }
            else if(newmatrix[i][j]==0 && newmatrix[k][j]==0)
                continue;
        }
    }
//------------------------------------------------------------------------
 for(int i=j+1;i<trow;i++)
  {
      for(int k=trow;k>=0;k--)
      {                                                                              //here it will calculate the value of each and every elements
          newmatrix[i][k]=(newmatrix[i][k]*newmatrix[j][j])-(newmatrix[j][k]*newmatrix[i][j]);      //of the echelon form.
      }
  }

}



//-----------------------------------------------------------------------------------------------------------------------
float t_value=0;
float newvalues[trow];
for(int h=0;h<trow;h++)
    newvalues[h]=1;

for(int i=trow-1;i>=0;i--)
{
    for(int j=0;j<trow+1;j++)
    {
        if(newmatrix[i][j]!=0)
        {
            for(int k=trow+1-2;k>j;k--)
            {
                t_value=t_value+(newmatrix[i][k]*newvalues[k]);
            }                                                               //CALCULATES newvalues OF VARIABLES
            newvalues[j]=(newmatrix[i][trow+1-1]-t_value)/newmatrix[i][j];
            t_value=0;
            break;
        }
    }

}
printf("\nTHE LEAST SQUARE SOLUTION GIVES:");
for(int i=0;i<trow;i++)
    printf("\nVALUE OF VARIABLE %d= %0.2f",i+1,newvalues[i]);

printf("\n\n-----------------------------------------------------------------------------------");



}
}





//////////////END OF MAIN BODY/////////////////////////END OF MAIN BODY/////////////////////////END OF MAIN BODY/////////////////////////END OF MAIN BODY/////////////////////////END OF MAIN BODY/////////////////////////END OF MAIN BODY///////////
