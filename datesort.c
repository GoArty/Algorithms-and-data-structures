#include <stdio.h>
#include <malloc.h>

struct Date {
    int Day, Month, Year;
};

struct Date* SortDates_Year(struct Date* dates, int n);
struct Date* SortDates_Month(struct Date* dates, int n);
struct Date* SortDates_Day(struct Date* dates, int n);

struct Date* SortDates(struct Date* dates, int n)
{
    dates = SortDates_Day(dates, n);
    dates = SortDates_Month(dates, n);
    dates = SortDates_Year(dates, n);
    return dates;
}

int main()
{
    int n;
    scanf("%d", &n);
    struct Date* dates = (struct Date*)malloc(n * sizeof(struct Date));
    for (int i = 0; i < n; i++)
        scanf("%04d %02d %02d", &dates[i].Year, &dates[i].Month, &dates[i].Day);

    dates = SortDates(dates, n);

    printf("\n");
    for (int i = 0; i < n; i++)
        printf("%04d %02d %02d\n", dates[i].Year, dates[i].Month, dates[i].Day);
    free(dates);
    return 0;
}

struct Date* SortDates_Year(struct Date* dates, int n)
{
    int count[62] = {0};
    struct Date *sup_arr_dates = (struct Date *)malloc(n * sizeof(struct Date));
    for (int i = 0; i < n; i++)
        count[dates[i].Year - 1970]++;
    for (int i = 0; i < 61; i++)
        count[i + 1] += count[i];
    for (int i = n-1; i >= 0; i--) {
        count[dates[i].Year - 1970]--;
        sup_arr_dates[count[dates[i].Year - 1970]] = dates[i];
    }
    for (int i = 0; i < n; i++)
        dates[i] = sup_arr_dates[i];
    free(sup_arr_dates);
    return dates;
}

struct Date* SortDates_Month(struct Date* dates, int n)
{
    int count[14] = {0};
    struct Date *sup_arr_dates = (struct Date *)malloc(n * sizeof(struct Date));
    for (int i = 0; i < n; i++)
        count[dates[i].Month]++;
    for (int i = 0; i < 12; i++)
        count[i + 1] += count[i];
    for (int i = n-1; i >= 0; i--) {
        count[dates[i].Month]--;
        sup_arr_dates[count[dates[i].Month]] = dates[i];
    }
    for (int i = 0; i < n; i++)
        dates[i] = sup_arr_dates[i];
    free(sup_arr_dates);
    return dates;
}

struct Date* SortDates_Day(struct Date* dates, int n)
{
    int count[33] = {0};
    struct Date *sup_arr_dates = (struct Date *)malloc(n * sizeof(struct Date));
    for (int i = 0; i < n; i++)
        count[dates[i].Day]++;
    for (int i = 0; i < 32; i++)
        count[i + 1] += count[i];
    for (int i = n-1; i >= 0; i--) {
        count[dates[i].Day]--;
        sup_arr_dates[count[dates[i].Day]] = dates[i];
    }
    for (int i = 0; i < n; i++)
        dates[i] = sup_arr_dates[i];
    free(sup_arr_dates);
    return dates;
}
