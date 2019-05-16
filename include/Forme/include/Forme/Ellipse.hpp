#ifndef ELLIPSE_HPP
#define ELLIPSE_HPP


#include "Forme.hpp"

/*Pourquoi fait on un h�ritage virtuel ?
		Dans cette biblioth�que nous ne g�rons pas tout ce qui touche aux interfaces. Or si une personne souhaite utiliser cette biblioth�que pour afficher ces formes il devra cr�er
		des classes qui h�rite de celle-ci. Cependant s'il reprend le sh�ma de notre biblioth�que il peut souhaiter faire classe abstraite pour ses formes. Donc une classe d'un objet
		affichable aurait comme h�ritage une classe forme (exemple rectangle), qui h�rite elle m�me de la classe abstraite Forme, et une classe abstraite (exemple FormeAffichable), qui
		h�rite elle aussi de la classe abstraite Forme.
		On voit donc ici un probleme, si on souhaite atteindre un membre de Forme comment fait-on au vu de l'ambiguit� ?
		Un solution est de pass� par l'h�ritage virtuelle comme �a la classe Forme sera la meme pour une classe de forme (exemple carr�) et pour la classe abstraite qui represente les formes
		affichable.

		Sans l'heritage virtuel on aurait quelque chose comme �a :	Forme   Forme								Alors qu'avec on a :		 Forme
																																	|			  |																						/  \
																																Carre   FormeAffichable														Carre	 FormeAffichable
																																		 \ /																							\	 /
																															 Carre Affichable																		Carre Affichable

*/

namespace fm {

class Ellipse : virtual public Forme {
	uint demiLargeur, demiHauteur;

protected:
	void ecrire(std::ostream & os) const override;

public:
	Ellipse(uint couleur, int x, int y, uint _demiLargeur, uint _demiHauteur);
	Ellipse(const Ellipse & ori);
	Ellipse(std::istream & is);
	~Ellipse() override;
	inline uint getDemiLargeur() const { return demiLargeur; }
	inline uint getDemiHauteur() const { return demiHauteur; }
	inline void setDemiLargeur(uint _demiLargeur) { demiLargeur = _demiLargeur; }
	inline void setDemiHauteur(uint _demiHauteur) { demiHauteur = _demiHauteur; }
	inline double perimetre() const override { return M_PI * std::sqrt( 2 * ( std::pow(demiLargeur,2) + std::pow(demiHauteur, 2))); }
};

}//namespace

#endif ELLIPSE_HPP
