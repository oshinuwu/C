#include <stdio.h>

// Define the structure type vehicle
struct vehicle {
    char owner_name[32];
    char brand[20];
    int kilometers_run;
    int price;
};

int main() {
    int n;

    // Prompt user to enter the number of vehicles
    printf("Enter the number of vehicles: ");
    scanf("%d", &n);

    // Define an array of structures to store information of n vehicles
    struct vehicle v[n];

    // Read data for n vehicles
    for (int i = 0; i < n; i++) {
        printf("Enter owner name for vehicle %d: ", i + 1);
        scanf("%s", v[i].owner_name);

        printf("Enter brand for vehicle %d: ", i + 1);
        scanf("%s", v[i].brand);

        printf("Enter kilometers run for vehicle %d: ", i + 1);
        scanf("%d", &v[i].kilometers_run);

        printf("Enter price for vehicle %d: ", i + 1);
        scanf("%d", &v[i].price);
    }

    // Calculate the total cost of all vehicles
    int total_cost = 0;
    for (int i = 0; i < n; i++) {
        total_cost += v[i].price;
    }

    // Display the total cost of all vehicles
    printf("Total cost of all vehicles: %d\n", total_cost);
    printf("Name:Oshin Pant\n Roll no:19\n Lab no:2");
    getch();
    return 0;
}
