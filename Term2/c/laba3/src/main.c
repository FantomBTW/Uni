#include <stdio.h>
#include <stdlib.h>
#include "fn.h"

int main() {
    FILE *file;
    double start = -3.5;
    double end = 8.0;
    double step = 0.1;
    int stepsCnt = 1000;

    file = fopen("graph_data.txt", "w");
    if (file == NULL) {
        printf("file error\n");
        return 1;
    }

    printf("Generating\n");
    for (double x = start; x <= end; x += step) {
        double y = get_function_value(x);
        fprintf(file, "%lf %lf\n", x, y);
    }
    fclose(file);
    printf("Data written to graph_data.txt\n");

    double total_area = integral(get_function_value, -3.1, 7.4, stepsCnt);
    
    double area1 = integral(get_function_value, -3.1, 0.0, stepsCnt);
    double area2 = integral(get_function_value, 0.0, 3.0, stepsCnt);
    double area3 = integral(get_function_value, 3.0, 7.4, stepsCnt);
    double sum_parts = area1 + area2 + area3;

    printf("\n\tIntegration Results\n");
    printf("Area (e^-x) on [-3.1, 0]:   %.4f\n", area1);
    printf("Area (0) on [0, 3]:   %.4f\n", area2);
    printf("Area (sin(x)) on [3, 7.4]:   %.4f\n", area3);
    printf("Sum of parts:   %.4f\n", sum_parts);
    printf("Total Area (direct calc):   %.4f\n", total_area);
    
    return 0;
}
