

double simpintegral(double *y,int ny,double dx)
{
        double sum=0;
        for(int i=0;i<ny;i++)
        {
                sum +=3*y[i];
        }
        for(int i=3;i<ny-1;i=i+3)
        {
                sum -= y[i];
        }
        sum =sum -2*(y[0]+y[ny-1]);
        sum =dx*3*sum*0.125;
        return sum;
}


