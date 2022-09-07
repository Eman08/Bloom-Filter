Created a bloom filter to filter out passwords users shouldn't use from commonly used passwords and previously used passwords

Objective:
- Create a vector of binary data for commonly used passwords after passing it through 15 hash functions to ensure no commonly used passwords are implemented
- User is asked to enter the password, if the password is a commonly used password, user is asked to reenter the password 
- A random salt value is then appended to the password which is then encrypted using SHA256 and store for higher security
- For updating the password, user is not able to enter an old password or something slightly similar, implemented using a vector of binary data which stores the old password
