#ifndef POLYGONE_HPP
#define POLYGONE_HPP

#include <vector>

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

class Polygone : virtual public Forme {
	std::vector<Point*> * tabPoint;
	size_t taille_tab;

	protected:
		void ecrire(std::ostream & os) const override;
		inline std::vector<Point*>* getTabPointPtr() const { return tabPoint; }
		inline Point* getPointPtrAt(size_t i) const { return tabPoint->at(i); }
		inline void setTabPoint(std::vector<Point*>* _tabPoint) { tabPoint = _tabPoint; taille_tab = tabPoint->size(); }

	public:
		Polygone(uint couleur, int x, int y, std::vector<Point*>* tabPoint);
		Polygone(const Polygone & ori);
		Polygone(std::istream & is);
		~Polygone() override;

		//Getter - Setter
		inline const Point* getPointAt(size_t i) const { return tabPoint->at(i); }
		inline void setPosPointAt(int x, int y, size_t i) { tabPoint->at(i)->setXY(x,y); }
		inline size_t getTailleTab() const { return taille_tab; }

		//Longueur de tous les cot�s
		double perimetre() const override;
};

}//namespace

#endif POLYGONE_HPP
