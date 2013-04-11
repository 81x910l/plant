#include "species.h"

#include "cohort_discrete.h"

// Specialisation for CohortDiscrete, where we add a cohort of the
// appropriate size at the back of the vector.
namespace model {

// This is a bit of a hassle, but a full specialisation will be
// compiled directly so cannot go into the header file (or it breaks
// the One Definition Rule).  We could get around this by inlining,
// but not sure if that is any better.

template <>
void Species<CohortDiscrete>::add_seeds(int n) {
  CohortDiscrete tmp(strategy, n);
  // Better might be to do:
  //   CohortDiscrete tmp(seed);
  //   tmp.set_n_individuals(n); // not yet written
  // because this will avoid calculating size variables on
  // initialisation, instead copying them from the seed.
  plants.push_back(tmp);
}

}