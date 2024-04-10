def check_duplicates(string):
    count = 1
    for i in range(len(string)):
        for j in range(i + 1, len(string)):
            if string[i] == string[j]:
                count += 1

                if count > 1:
                    print(f"{string[i]} appears {count} times.")
                else:
                    return False
                
check_duplicates("helloo")