struct date
{
    int day;
    int month;
    int year;
};

int validate_date (struct date d)
{
    if (d.month<1 || d.month >12||d.day >31 ||d.day < 1)
        return 0;
    if (d.month ==2 )
        if (d.day >28)
            return 0;
    else if (d.month == 4 || d.month == 6 || d.month == 9 || d.month == 11)
        if (d.day > 30)
            return 0;
    else 
    return 1;
}