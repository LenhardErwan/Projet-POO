#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP


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

class Triangle : virtual public Forme {
	Point *p1, *p2;

	protected:
		void ecrire(std::ostream & os) const override;
		inline Point* getPtrP1() { return p1; }
		inline Point* getPtrP2() { return p2; }

	public:
		Triangle(uint couleur, int x, int y, Point * p1, Point * p2);
		Triangle(const Triangle & ori);
		Triangle(std::istream & is);
		~Triangle() override;

		//Getter - Setter
		inline const Point & getP1() const { return *p1; }
		inline void setP1(int x, int y) { p1->setXY(x,y); }
		inline const Point & getP2() const { return *p2; }
		inline void setP2(int x, int y) { p2->setXY(x, y); }

		//Longueur des trois cot�s
		inline double perimetre() const override { return (getLonSeg(getAncre(), getP1()) + getLonSeg(getP1(), getP2()) + getLonSeg(getP2(), getAncre()) ); }
};

}//namespace

#endif TRIANGLE_HPP
