has_multi = True

day_in_month = {0: 31, 1: 28, 2: 31, 3: 30, 4: 31, 5: 30, 6: 31, 7: 31, 8: 30, 9: 31, 10: 30, 11: 31}

def is_leap(y):
    return (y % 4 == 0 and y % 100 != 0) or (y % 400 == 0)

def get_days(date):
    """
    number of day between dates d1 and d2 = number of complete years between two dates * 365(step1) +
                                            number of leap years between two dates excluding the start and end year(step2) +
                                            number of days in the start year(step3) +
                                            number of days in the end year(step 4)

    - in our case start year is always a complete year, 
        therefore we consider when calculating in step1 and step2 
        and exclude step 4

    number of leap years between two years = number of leap years seen including y2 - 
                                             number of leap years seen excluding y1
    ex : between 1900 and 2000
    number of leap years = (2000 // 4 - 2000 // 100 + 2000 // 400) - 
                            (1899 // 4 - 1899 // 100 + 1899 // 400)     

    """
    y, m, d = date

    days = (y - 1900) * 365 # calculating days considering all years are non leap
    days += (y // 4 - y // 100 + y // 400) - (1899 // 4 - 1899 // 100 + 1899 // 400) - (1 if is_leap(y) else 0) # adding number of leap years between [1900, y)
    for i in range(0, m-1): # adding days of complete months in y
        days += day_in_month[i] + 1 if i == 1 and is_leap(y) else day_in_month[i]
    
    days += d # adding days of m which is incomplete

    return days 

for _ in range(int(input()) if has_multi else 1):
    date1 = tuple(map(int, input().split()))
    date2 = tuple(map(int, input().split()))

    days_since_1900_1_1 = get_days(date1)
    
    # finding weekday on the start date
    weekday = (days_since_1900_1_1) % 7

    y1, m1, d1 = date1
    y2, m2, d2 = date2

    # set sundays on first to 1 in start date is on first of a month and is a sunday
    sundays_on_first = 1 if d1 == 1 and weekday == 0 else 0

    # updating weekday after starting month (potentially in complete month)
    weekday = (weekday + (day_in_month[m1-1] + 1 if m1 == 2 and is_leap(y1) else day_in_month[m1-1]) - d1 + 1) % 7 

    # iterating throught all other months untill end data and count sundays on the first of a month
    for year in range(y1, y2+1):
        for month in range(m1 if year == y1 else 0, m2 if year == y2 else 12):
             
            if weekday == 0:
                sundays_on_first += 1
        
            weekday = (weekday + (day_in_month[month] + 1 if month == 1 and is_leap(year) else day_in_month[month])) % 7

    print(sundays_on_first)