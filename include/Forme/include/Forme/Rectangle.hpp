#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

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

class Rectangle : public virtual Forme {
	uint largeur, hauteur;

	protected:
		void ecrire(std::ostream & os) const override;

	public:
		Rectangle(uint couleur, int x, int y, uint _largeur, uint _hauteur);
		Rectangle(const Rectangle & ori);
		Rectangle(std::istream & is);
		~Rectangle() override;
		inline uint getLargeur() const { return largeur; }
		inline uint getHauteur() const { return hauteur; }
		inline void setLargeur(uint _largeur) { largeur = _largeur; }
		inline void setHauteur(uint _hauteur) { hauteur = _hauteur; }
		inline double perimetre() const override { return 2 * (hauteur + largeur); }
};

}//namespace

#endif RECTANGLE_HPP
