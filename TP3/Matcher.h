/*
 * Matcher.h 
 *
 *      Author: Robles Lucas Jose
 *      Padrón: 87944
 */

#ifndef __MATCHER_h__
#define __MATCHER_h__

// ATRIBUTOS MATCHER:
//
// FILIACION: Filiación del jugador
//

// FUNCIONAMIENTO Operator:
// Compara la filiación del jugador 
// con la de un objeto T. Este debe
// poseer filiación.

namespace myMatcher { 
  template <typename T>
    class Matcher {
  private:
    int parentezco;
  public:
    explicit Matcher(int filiacion) {parentezco = filiacion;}
    bool operator()(T* elem) {
      if (elem->GetFiliacion() == parentezco)
	return true;
      else return false;
    }
  };
}

#endif
