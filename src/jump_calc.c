#include <stdio.h>
#include <time.h>

int graph_vars(int *one_jump, int *length, int steps) {
    static int counter=0;
    if (*length > steps) {
        for (int next_step_len = 1;  next_step_len <= *one_jump; next_step_len++) {
            graph_vars(one_jump, length, steps + next_step_len);
        }
    } else if (*length == steps) {
        counter += 1;
    }
    return counter;
}

int main() {
    int max_steps, all_steps, variants;
    clock_t t;
    char *input_name = "INPUT.TXT";
    char *output_name = "OUTPUT.TXT";
    FILE *input_data, *out_data;

    input_data = fopen(input_name, "r");
    if (input_data == NULL)
    {
        printf("No such file %s", input_name);
        return 1;
    } else {
        fscanf(input_data, "%d %d", &max_steps, &all_steps);
        printf("max steps per jump: %d;\nall steps: %d;\n", max_steps, all_steps);
    }
    fclose(input_data);
    t = clock();
    variants = graph_vars(&max_steps, &all_steps, 0);
    t = clock();
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
    printf("variants: %d; \ntook %f seconds\n", variants, time_taken);
    out_data = fopen(output_name,"w");
    fprintf(out_data, "%d", variants);
    fclose(out_data);
    return 0;
}