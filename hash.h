#ifndef HASH_H
#define HASH_H

#include <iostream>
#include <cmath>
#include <random>
#include <chrono>

typedef std::size_t HASH_INDEX_T;

struct MyStringHash {
    HASH_INDEX_T rValues[5] { 983132572, 1468777056, 552714139, 984953261, 261934300 };
    MyStringHash(bool debug = true)
    {
        if(false == debug){
            generateRValues();
        }
    }
    // hash function entry point (i.e. this is h(k))
    HASH_INDEX_T operator()(const std::string& k) const
    {
        // Add your code here
       // std::string clean = "";
       // for(char ch : k)
       // {
       //     if(std::isalnum(ch))
       //     {
        //        clean+=std::tolower(ch);
        //    }
      //  }
      //  HASH_INDEX_T w[5] = {0};
        //int chunkIndex = 4;
       // int i = static_cast<int>(clean.size());
        //int length = clean.length();
        //int block = 0;
        //int block = 4;
        //for(int i = length; i >= 0 && block < 5; )
       // for(int i = length-1; i >= 0 && block < 5; )
      //  {
       //     HASH_INDEX_T current = 0;
           // int power = 1;
            //for(int j = 0; j < 6 && i >= 0; ++j; --i)
         //   for(int j = 0; j < 6 && i >= 0; ++j, --i)
         //   {
             //   current+=letterDigitToNumber(clean[i]) * power;
             //   power*=36;
          //  }
          //  w[4-block] = current;
         //   block++;
      //  }
     // while(i > 0 && chunkIndex >= 0)
    // int strIndex = static_cast<int>(clean.size());
     //for(int i =0; i < 5 && strIndex > 0; ++i)
    // for(int i = 4; i>= 0 && strIndex > 0; --i)
    //  {
     //   int chunkStart = std::max(0, strIndex-6);
     //   std::string chunk = clean.substr(chunkStart, strIndex-chunkStart);
        //HASH_INDEX_T val = 0;
     //   strIndex = chunkStart;
     //   HASH_INDEX_T val = 0;
        //for(char c : chunk)
       // {
       //     val = val * 36 + letterDigitToNumber(c);
       // }
       // w[chunkIndex] = val;
     //   i-=chunk.length();
      //  chunkIndex--;
        //w[i] = val;
      //  HASH_INDEX_T power = 1;
      //  for(int j = static_cast<int>(chunk.size())-1; j>=0; --j)
     //   {
     //       val+=letterDigitToNumber(chunk[j]) * power;
      //      power*=36;
     //   }
     //   w[i] = val;
     // }
    //  HASH_INDEX_T h = 0;
    //  for(int i = 0; i < 5; ++i)
    //  {
    //    h+=rValues[i] * w[i];
    //  }
    //  return h;
        //while(length > 0 && block >= 0)
       // {
          //  int chunkStart = std::max(0, length-6);
          //  std::string chunk = clean.substr(chunkStart, length-chunkStart);

          //  HASH_INDEX_T val = 0;
          //  for(char c : chunk)
         //   {
         //       val = val * 36 + letterDigitToNumber(c);
         //   }
            //w[block]=val;
         //   w[4-block] = val;
         //   length-=chunk.length();
         //   block--;
       // }

       // HASH_INDEX_T h = 0;
        //for(int i = 0; i < 5; ++i)
       // {
        //    h+=rValues[i] * w[i];
       // }
       // return h;
       std::string clean = "";
       for(char ch : k)
       {
        if(std::isalnum(ch))
        {
            clean+=std::tolower(static_cast<unsigned char>(ch));
        }
       }
       HASH_INDEX_T w[5] = {0};
       int len = clean.length();
       //int wInd = 4;
       int chunkIndex = 0;
       //while(len > 0 && wInd >= 0)
       while(len > 0 && chunkIndex < 5)
       {
        int chunkStart = std::max(0, len-6);
        std::string chunk = clean.substr(chunkStart, len-chunkStart);
        HASH_INDEX_T val = 0;
        //HASH_INDEX_T power = 1;

      //  for(int i = static_cast<int>(chunk.size())-1; i >=0; --i)
      //  {
       //     val+=letterDigitToNumber(chunk[i]) * power;
         //   power*=36;
       // }
       for(char c : chunk)
       {
        val = val*36 +letterDigitToNumber(c);
       }
        w[4-chunkIndex] = val;
        chunkIndex++;
        len = chunkStart;
        //wInd--;
       }
       HASH_INDEX_T h = 0;
       for(int i = 0; i < 5; ++i)
       {
            h+=rValues[i] * w[i];
       }
       return h;

    }

    // A likely helper function is to convert a-z,0-9 to an integral value 0-35
    HASH_INDEX_T letterDigitToNumber(char letter) const
    {
        // Add code here or delete this helper function if you do not want it
        if(letter >= 'a' && letter <= 'z')
        {
            return letter - 'a';
        }
       // else if(letter >= 'A' && letter <= 'Z')
        //{
         //   return 10 + (letter-'A');
       // }
        else if(letter >= '0' && letter <= '9')
        {
            return 26 + (letter-'0');
        }
        else
        {
            throw std::invalid_argument("Invalid character for hashing");
        }


    }

    // Code to generate the random R values
    void generateRValues()
    {
        // obtain a seed from the system clock:
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::mt19937 generator (seed);  // mt19937 is a standard random number generator

        // Simply call generator() [it has an operator()] to get another random number
        for(int i{ 0 }; i < 5; ++i)
        {
            rValues[i] = generator();
        }
    }
};

#endif
