#include <stdio.h>
#include <math.h>
#define X_MIN 0.0
#define X_MAX 2.0*M_PI
#define N 1000
    
int main(void)
{
    FILE *gp, *file;
    char *file_name;
    double x, y, d;
    file_name = "data.dat";
    file = fopen(file_name, "w");
    
    d = (X_MAX-X_MIN)/N;
    for(int i=0; i<=N; i++)
    {
        x = X_MIN + i*d;
        y = sin(x);
        fprintf(file, "%f\t%f\n", x, y);
    }
    fclose(file);
    
    gp = popen("gnuplot -persist", "w");
    fprintf(gp, "set title \"Q4 result\"\n");
    fprintf(gp, "set title font\"Arial,12\"\n");
    fprintf(gp, "set xlabel \"x\"\n");
    fprintf(gp, "set xrange [%f:%f]\n", X_MIN, X_MAX);
    fprintf(gp, "set xtics %f\n", (X_MAX-X_MIN)/4);
    fprintf(gp, "set format x \"%2.1P{/Symbol p}\"\n");
    fprintf(gp, "set ylabel \"y\"\n");
    fprintf(gp, "set yrange [-1.1:1.1]\n");
    fprintf(gp, "set ytics 0.5\n");
    /*fprintf(gp, "set format y \"%2.1f\"\n");*/
    fprintf(gp, "plot \"%s\" with lines linetype 1 title \"y=sin(x)\"\n", file_name);
    
    pclose(gp);
    
    return 0;
}