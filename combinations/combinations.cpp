#include <iostream>
#include <string>

int main(int argc, char const *argv[]) {
  //count variable holds number of possible combinations found
  int count = 0;
  //z variable keeps track of current number of tile values in the set, max of 14
  int z;
  //14X nested for loop to run the max possible number of tiles in a combination: 14 1-sized tiles

  //Disclaimer: I know how inefficient nested for loops can be, however with tested "break;" statements, worst possible scenerio is 2x as long as the data set for time complexity
  /*
  Algorithm: For each for loop, subtract current value in for loop (1-6) from z (tile value of combination) and test if z is less than 0,
  if less than 0, break for loop and continue back up to previous for loop while returning z to previous value
  if = to 0, add to combination and continue current for loop while increasing value of count
  */
  for (int a = 1; a <= 6; a++) {
    z = 14 - a;
    for (int b = 1; b <= 6; b++) {
      z-=b;
      for (int c = 1; c <= 6; c++) {
        z-=c;
        if (z<0) {
          z+=c;
          break;
        }
        if (z==0) {
          z+=c;
          count++;
          break;
        }
        for (int d = 1; d <= 6; d++) {
          z-=d;
          if (z<0) {
            z+=d;
            break;
          }
          if (z==0) {
            z+=d;
            count++;
            break;
          }
          for (int e = 1; e <= 6; e++) {
            z-=e;
            if (z<0) {
              z+=e;
              break;
            }
            if (z==0) {
              z+=e;
              count++;
              break;
            }
            for (int f = 1; f <= 6; f++) {
              z-=f;
              if (z<0) {
                z+=f;
                break;
              }
              if (z==0) {
                z+=f;
                count++;
                break;
              }
              for (int g = 1; g <= 6; g++) {
                z-=g;
                if (z<0) {
                  z+=g;
                  break;
                }
                if (z==0) {
                  z+=g;
                  count++;
                  break;
                }
                for (int h = 1; h <= 6; h++) {
                  z-=h;
                  if (z<0) {
                    z+=h;
                    break;
                  }
                  if (z==0) {
                    z+=h;
                    count++;
                    break;
                  }
                  for (int i = 1; i <= 6; i++) {
                    z-=i;
                    if (z<0) {
                      z+=i;
                      break;
                    }
                    if (z==0) {
                      z+=i;
                      count++;
                      break;
                    }
                    for (int j = 1; j <= 6; j++) {
                      z-=j;
                      if (z<0) {
                        z+=j;
                        break;
                      }
                      if (z==0) {
                        z+=j;
                        count++;
                        break;
                      }
                      for (int k = 1; k <= 6; k++) {
                        z-=k;
                        if (z<0) {
                          z+=k;
                          break;
                        }
                        if (z==0) {
                          z+=k;
                          count++;
                          break;
                        }
                        for (int l = 1; l <= 6; l++) {
                          z-=l;
                          if (z<0) {
                            z+=l;
                            break;
                          }
                          if (z==0) {
                            z+=l;
                            count++;
                            break;
                          }
                          for (int m = 1; m <= 6; m++) {
                            z-=m;
                            if (z<0) {
                              z+=m;
                              break;
                            }
                            if (z==0) {
                              z+=m;
                              count++;
                              break;
                            }
                            for (int n = 1; n <= 6; n++) {
                              z-=n;
                              if (z<0) {
                                z+=n;
                                break;
                              }
                              if (z==0) {
                                z+=n;
                                count++;
                                break;
                              }
                              z+=n;
                            }
                            z+=m;
                          }
                          z+=l;
                        }
                        z+=k;
                      }
                      z+=j;
                    }
                    z+=i;
                  }
                  z+=h;
                }
                z+=g;
              }
              z+=f;
            }
            z+=e;
          }
          z+=d;
        }
        z+=c;
      }
      z+=b;
    }
    z+=a;
  }
  //print number of possibilities to the console
  std::cout << "Number of possibilities: " << count << "\n";
  return 0;
}
