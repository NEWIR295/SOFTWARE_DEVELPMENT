#!/bin/bash

# List of names
names=(
"abdelrahman yehia sayed"
"Abdullah ayman mohammed alamin"
"Adham Muhhamed Fathy hassan"
"Ahmed sameh al sayed ahmed"
"Christine Ayman Fahim Khalil"
"ebraam ehab nazir ghobrial"
"Eman Ahmed Ramadan Mahmoud"
"Fatma Osama Mahmoud Ahmed"
"Hamed Elsiddig Mohamed Ali Omer"
"menna mahmoud saber ebrahim"
"Mennatallah Mohamed Awad Abdelaal"
"Mohamed Amr Ahmed Khattab"
"Mohamed Gamal Mohamed Othman"
"Mohamed sherif elnbrawy mohamed"
"Mostafa mohamed saleh fath allah"
"Muhammad Fawzy Taha Muhammad"
"Mustafa Fathi Abdelshakour Mohamed"
"roaa mohamed ali abdelhadi"
"Sabir Abdu Abdelkarem Suliman"
"Saeed Yasser Abdulbadeea"
"Saif eldeen fathy ali"
"Shahd Mohamed Sayed hassan"
"Ziad Gamal Ahmed Abdelrahman"
"Ziad Maged Mostafa Hussien"
"ziad waleed mohamed salah"
"Ahmed Helal Ahmed Ismail"
"Sagda Hossameldin Ibrahim Madbouly"
"AlHussien Mustafa Hassan Abdelmeged"
"Amr khaled abdalfadel mohamed"
"Taha Ahmed Hussein Mohamed aboelela"
"Amr Mohamed Ali"
)

id=1
for name in "${names[@]}"; do
    # Keep only first 3 parts (FirstName, MiddleName, LastName)
    short_name=$(echo "$name" | awk '{print $1, $2, $NF}')
    
    # Convert to Title Case
    formatted_name=$(echo "$short_name" | awk '{for (i=1;i<=NF;i++) $i=toupper(substr($i,1,1)) tolower(substr($i,2)); print}' | tr ' ' '_')
    
    # Build final directory name
    dir_name=$(printf "%02d_%s" "$id" "$formatted_name")
    
    # Create directory structure
    mkdir -p "$dir_name"/{C_COURSE,AVR_Course}/{ASSIGNMENTS,PROJECT}
    touch "$dir_name"/{C_COURSE,AVR_Course}/{ASSIGNMENTS,PROJECT}/README.md
    
    ((id++))
done

echo "All student directories with course folders created successfully."

