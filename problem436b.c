#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef char bool;

inline bool s_over_one (double s) {
  return (s > 1.0);
}

inline bool s_over_two (double s) {
  return (s > 2.0);
}

inline double random_double () {
  return ( (double) rand () / (double) RAND_MAX );
}

inline long double probability_player_two_wins (long number_simulations) {
  double S = 0.0;
  double player_one_random = 0.0;
  double player_two_random = 0.0;

  long iterations = 0;
  long player_two_score = 0;

  while (iterations < number_simulations) {
    while (!s_over_one (S)) {
      player_one_random = random_double ();
      S += player_one_random;
    }

    while (!s_over_two(S)) {
      player_two_random = random_double ();
      S += player_two_random;
    }
    if (player_two_random > player_one_random) player_two_score++;
    S = 0.0;
    iterations++;
  }
  return (long double) player_two_score / (long double) number_simulations;
}

int main () {
  const long NUMBER_REQUIRED = 10000000000000;
  srand (time(NULL));
  printf ("%.15Lf\n", probability_player_two_wins (NUMBER_REQUIRED));
}
