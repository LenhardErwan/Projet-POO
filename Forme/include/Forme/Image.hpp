#ifndef IMAGE_HPP
#define IMAGE_HPP


#include "Forme/Forme.hpp"
#include "Forme/Point.hpp"

namespace fm {

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

class Image : virtual public Forme {
	Point *p1;
	std::string img;


	protected:
		void ecrire(std::ostream & os) const override;
		inline Point* getPtrP1() { return p1; }

	public:
		Image(std::string img, int x, int y, Point * p1);
		Image(const Image & ori);
		Image(std::istream & is);
		~Image() override;

		//Getter - Setter
		inline const Point & getP1() const { return *p1; }
		inline void setP1(int x, int y) { p1->setXY(x,y); }
		inline std::string getImg() const { return img ; }

		//Longueur des trois cot�s
		inline double perimetre() const override { return (2 * (getP1().getX() - getAncre().getX()) + 2* (getP1().getY() - getAncre().getY())); }
};

}//namespace

#endif IMAGE_HPP
