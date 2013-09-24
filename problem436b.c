#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define ANSWERE_FORMAT "%.15Lf\n"

typedef char bool;

bool s_over_one (double s) {
  return (s > 1.0);
}

bool s_over_two (double s) {
  return (s > 2.0);
}

double random_double () {
  return ( (double) rand () / (double) RAND_MAX );
}

long double probability_player_two_wins (long max_iterations, long iterations_per_feedback) {
  double S = 0.0;
  double player_one_random = 0.0;
  double player_two_random = 0.0;

  long iterations = 0;
  long player_two_score = 0;
  
  time_t start_time = clock ();

  while (iterations < max_iterations) {
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
    if (iterations % iterations_per_feedback == 0) {
      printf ("Iterations: %ld\tRemaining: %ld\tEstimate: ",iterations, max_iterations - iterations);
      printf (ANSWERE_FORMAT, (long double) player_two_score / (long double) iterations); 
    }
  }

  time_t end_time = clock ();
  printf ("Time taken %lfS\n", (double)(end_time - start_time)/1000000.0);
  return (long double) player_two_score / (long double) max_iterations;
}

int main () {
  const long NUMBER_REQUIRED = 10000000000;
  const long ITERATIONS_PER_FEED_BACK = 5000000;
  srand (time(NULL));
  printf (ANSWERE_FORMAT, probability_player_two_wins (NUMBER_REQUIRED, ITERATIONS_PER_FEED_BACK));
}
