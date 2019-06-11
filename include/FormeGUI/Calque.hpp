#ifndef CALQUE_HPP
#define CALQUE_HPP

#include <iostream>
#include <vector>

#include "FormeDrawable.hpp"
#include "PolygoneDrawable.hpp"
#include "TriangleDrawable.hpp"
#include "ImageDrawable.hpp"

/**
* \class Calque Calque.hpp "Calque.hpp"
* \brief Classe pour d�finir les calques
* \authors DI NARDO Valentin, LENHARD Erwan
* \version 1.0
* \date 11 juin 2019
*/
class Calque {


	///\var bool active
	///\brief Booleen pour savoir si le calque est actif ou pas
	bool active;

	///\var std::vector<FormeD*> * tab_forme
	///\brief Tableau de FormeD*
	std::vector<FormeD*> * tab_forme;

	///\var std::vector<PointD*> * tab_point
	///\brief Tableau de PointD*
	std::vector<PointD*> * tab_point;

	public:
		/// \brief constructeur de Forme
		/// \param bool active vrai
		Calque(bool active = true);

		/// \brief destructeur de Forme
		~Calque();

		/// \brief ajouter une Forme au tableau de FormeD*
		/// \param FormeD*
		/// \return void
		void ajouter(FormeD * forme);

		/// \brief ajouter un PointD* au tableau de PointD*
		/// \param PointD*
		/// \return void
		void ajouter(PointD * point);

		/// \brief supprimer une FormeD dand le tableau de FormeD*
		/// \param FormeD*
		/// \return void
		void delInTab(FormeD * forme);

		/// \brief lib�rer la m�moire de la FormeD supprimer
		/// \param FormeD*
		/// \return void
		void supprimer(FormeD * forme);

		/// \brief supprimer un PointD dans le tableau de Forme
		/// \param PointD*
		/// \return void
		void delInTab(PointD * point);

		/// \brief lib�rer la m�moire de la FormeD supprimer
		/// \param PointD*
		/// \return void
		void supprimer(PointD * point);

		/// \brief Permet de savoir si la souris est sur une forme du Calque
		/// \param position x de la souris
		/// \param position y de la souris
		/// \return FormeD*
		FormeD * isOverForme(int x, int y) const;

		/// \brief Permet de savoir si la souris est sur un point du Calque
		/// \param position x de la souris
		/// \param position y de la souris
		/// \return PointD*
		PointD * isOverPoint(int x, int y) const;

		/// \brief Permet de dessiner toutes les Formes contenues dans le Calque
		/// \param window sf::RenderWindow fenetre d'affichage principale
		/// \return void
		void dessiner(sf::RenderWindow &window) const;

		/// \brief Permet de savoir si la Forme en param�tre est dans le tableau
		/// \param FormeD* Forme prise en param�tre
		/// \return bool
		bool isInTab(FormeD * shape) const;

		/// \brief Permet de savoir si le Point en param�tre est dans le tableau
		/// \param PointD* Point pris en param�tre
		/// \return bool
		bool isInTab(PointD * point) const;

		/// \brief Permet de savoir si le Point est dans la Forme
		/// \param PointD* Point pris en param�tre
		/// \return bool
		bool pointInShape(PointD * point) const;

		/// \brief Permet de retourner le nombre de Forme dans le tableau de Forme
		/// \return size_t
		inline size_t getNbFormes() const { return tab_forme->size(); }

		/// \brief Permet de retourner le nombre de Point dans le tableau de Point
		/// \return size_t
		inline size_t getNbPoints() const { return tab_point->size(); }

		/// \brief Permet de retourner la Forme a la position i dans le tableau de Forme
		/// \param size_t
		/// \return FormeD* 
		inline FormeD* getFormeAt(size_t i) const { return tab_forme->at(i); }

		/// \brief Permet de retourner la Point a la position i dans le tableau de Point
		/// \param size_t
		/// \return PointD*
		inline PointD* getPointAt(size_t i) const { return tab_point->at(i); }

		/// \brief Retourne le booleen active
		/// \return bool
		inline bool isActive() const { return active; }

		/// \brief Inverse le booleen active
		/// \return bool
		inline void toggleActive() { active = !active; }

	private:
		/// \brief Permet de retourner la position de la Forme pass�e en param�tre
		/// \param FormeD*
		/// \return size_t
		size_t getPosShape(FormeD * shape) const; 

		/// \brief Permet de retourner la position de la Point pass�e en param�tre
		/// \param PointD*
		/// \return size_t
		size_t getPosPoint(PointD * point) const; 
};

#endif CALQUE_HPP