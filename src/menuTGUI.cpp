#include "MenuTGUI.hpp"

Menu::Menu(sf::VideoMode mode, const sf::String & title, sf::Uint32 style, const sf::ContextSettings & settings) 
	: sf::RenderWindow(mode, title, style, settings)
{
	gui = new tgui::Gui(*this);

	initialiseDisplay();
}

Menu::~Menu() {}

void Menu::setView(const sf::View &view) {
	RenderTarget::setView(view);
	gui->setView(getView());
}

void Menu::passEvent(sf::Event event) {
	switch (event.type) {
		//Fenetre ferm�
		case sf::Event::Closed:
			close();
			break;

			//fenetre resize
		case sf::Event::Resized:
			setView(sf::View(sf::FloatRect(0, 0, (float)event.size.width, (float)event.size.height)));
			break;

		case sf::Event::KeyPressed:
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {	//Active le bouton createShapeButton
				createShapeButton->setFocused(true);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace) || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {	//Active le bouton closeAddShapeButton
				closeAddShapeButton->setFocused(true);	//Focus le bouton close
				sf::Event::KeyEvent data;	//Creer un evenement d'une touche du clavier
				data.code = sf::Keyboard::Enter;	//Met la touche du clavier sur enter
				closeAddShapeButton->keyPressed(data);	//Active le bouton
			}

			break;

		default:
			break;
	}
	gui->handleEvent(event);
}


void Menu::initialiseDisplay() {
	addPointButton = tgui::Button::create();
	addPointButton->setPosition("5%", "5");
	addPointButton->setSize("90%", "25");
	addPointButton->setText("Ajouter Point");
	gui->add(addPointButton, "addPointButton");

	addRectangleButton = tgui::Button::create();
	addRectangleButton->setPosition("5%", "addPointButton.bottom + 5");
	addRectangleButton->setSize("90%", "25");
	addRectangleButton->setText("Ajouter Rectangle");
	gui->add(addRectangleButton, "addRectangleButton");
	
	addEllipseButton = tgui::Button::create();
	addEllipseButton->setPosition("5%", "addRectangleButton.bottom + 5");
	addEllipseButton->setSize("90%", "25");
	addEllipseButton->setText("Ajouter Ellipse");
	gui->add(addEllipseButton, "addEllipseButton");
	
	addCarreButton = tgui::Button::create();
	addCarreButton->setPosition("5%", "addEllipseButton.bottom + 5");
	addCarreButton->setSize("90%", "25");
	addCarreButton->setText(std::string("Ajouter Carr�"));	//std::string pour avoir le �
	gui->add(addCarreButton, "addCarreButton");

	addCercleButton = tgui::Button::create();
	addCercleButton->setPosition("5%", "addCarreButton.bottom + 5");
	addCercleButton->setSize("90%", "25");
	addCercleButton->setText("Ajouter Cercle");
	gui->add(addCercleButton, "addCercleButton");

	addTriangleButton = tgui::Button::create();
	addTriangleButton->setPosition("5%", "addCercleButton.bottom + 5");
	addTriangleButton->setSize("90%", "25");
	addTriangleButton->setText("Ajouter Triangle");
	gui->add(addTriangleButton, "addTriangleButton");

	addPolygoneButton = tgui::Button::create();
	addPolygoneButton->setPosition("5%", "addTriangleButton.bottom + 5");
	addPolygoneButton->setSize("90%", "25");
	addPolygoneButton->setText("Ajouter Polygone");
	gui->add(addPolygoneButton, "addPolygoneButton");

	addImageButton = tgui::Button::create();
	addImageButton->setPosition("5%", "addPolygoneButton.bottom + 5");
	addImageButton->setSize("90%", "25");
	addImageButton->setText("Ajouter Image");
	gui->add(addImageButton, "addImageButton");

	widthLabel = tgui::Label::create("Largeur :");
	widthLabel->setPosition("5%", "addImageButton.bottom + 100");
	widthLabel->setVisible(false);
	widthEb = tgui::EditBox::create();
	widthEb->setPosition("5%", "widthLabel.bottom");
	widthEb->setSize("90%", "30");
	widthEb->setDefaultText("Nombre");
	widthEb->setVisible(false);
	gui->add(widthLabel, "widthLabel");
	gui->add(widthEb, "widthEb");

	heightLabel = tgui::Label::create("Hauteur :");
	heightLabel->setSize("90%", "20");
	heightLabel->setPosition("5%", "widthEb.bottom + 5");
	heightLabel->setVisible(false);
	heightEb = tgui::EditBox::create();
	heightEb->setPosition("5%", "heightLabel.bottom");
	heightEb->setSize("90%", "30");
	heightEb->setDefaultText("Nombre");
	heightEb->setVisible(false);
	gui->add(heightLabel, "heightLabel");
	gui->add(heightEb, "heightEb");

	singleLabel = tgui::Label::create("valeur");
	singleLabel->setSize("90%", "20");
	singleLabel->setPosition("5%", "addImageButton.bottom + 100");
	singleLabel->setVisible(false);
	singleEb = tgui::EditBox::create();
	singleEb->setPosition("5%", "singleLabel.bottom");
	singleEb->setSize("90%", "30");
	singleEb->setDefaultText("Nombre");
	singleEb->setVisible(false);
	gui->add(singleLabel, "singleLabel");
	gui->add(singleEb, "singleEb");

	ancreLabel = tgui::Label::create("Position de l'ancre :");
	ancreLabel->setSize("80%", "20");
	ancreLabel->setPosition("5%", "addImageButton.bottom + 100");
	ancreLabel->setVisible(false);
	gui->add(ancreLabel, "ancreLabel");

	posXLabel = tgui::Label::create("Position X :");
	posXLabel->setSize("40%", "20");
	posXLabel->setPosition("5%", "ancreLabel.bottom");
	posXLabel->setVisible(false);
	posXEb = tgui::EditBox::create();
	posXEb->setPosition("5%", "posXLabel.bottom");
	posXEb->setSize("40%", "30");
	posXEb->setDefaultText("Nombre");
	posXEb->setVisible(false);
	gui->add(posXLabel, "posXLabel");
	gui->add(posXEb, "posXEb");

	posYLabel = tgui::Label::create("Position Y :");
	posYLabel->setSize("40%", "20");
	posYLabel->setPosition("posXLabel.right + 10%", "ancreLabel.bottom");
	posYLabel->setVisible(false);
	posYEb = tgui::EditBox::create();
	posYEb->setPosition("posXEb.right + 10%", "posYLabel.bottom");
	posYEb->setSize("40%", "30");
	posYEb->setDefaultText("Nombre");
	posYEb->setVisible(false);
	gui->add(posYLabel, "posYLabel");
	gui->add(posYEb, "posYEb");

	closeAddShapeButton = tgui::Button::create();
	closeAddShapeButton->setPosition("5%", "posXEb.bottom + 30");
	closeAddShapeButton->setSize("25%", "25");
	closeAddShapeButton->setText("Fermer");
	closeAddShapeButton->setVisible(false);
	gui->add(closeAddShapeButton, "closeAddShapeButton");

	createShapeButton = tgui::Button::create();
	createShapeButton->setPosition("closeAddShapeButton.right + 40%", "posXEb.bottom + 30");
	createShapeButton->setSize("25%", "25");
	createShapeButton->setText("Cr�er");
	createShapeButton->setVisible(false);
	gui->add(createShapeButton, "createShapeButton");


	initialiseConnect();
}

void Menu::initialiseConnect() {
	addPointButton->connect("pressed", &Menu::displayDefault, this, std::string("point"));
	addRectangleButton->connect("pressed", &Menu::display2ValuesConstructor, this, std::string("rectangle"));
	addEllipseButton->connect("pressed", &Menu::display2ValuesConstructor, this, std::string("ellipse"));
	addCercleButton->connect("pressed", &Menu::display1ValueConstructor, this, std::string("cercle"));
	addCarreButton->connect("pressed", &Menu::display1ValueConstructor, this, std::string("carre"));
	addImageButton->connect("pressed", &Menu::display1ValueConstructor, this, std::string("image"));
	closeAddShapeButton->connect("pressed", &Menu::hiddingAddShape, this);
}

void Menu::displayDefault(std::string type) {
	hiddingAddShape(); //reset 

	ancreLabel->setPosition("5%", "addImageButton.bottom + 100");
	ancreLabel->setVisible(true);

	posXLabel->setVisible(true);
	posXEb->setVisible(true);

	posYLabel->setVisible(true);
	posYEb->setVisible(true);

	createShapeButton->setVisible(true);
	closeAddShapeButton->setVisible(true);

	if (type == "point") createShapeButton->connect("pressed", &Menu::createPoint, this);
}

void Menu::display2ValuesConstructor(std::string type) {
	displayDefault();

	widthLabel->setVisible(true);
	widthEb->setVisible(true);

	heightLabel->setVisible(true);
	heightEb->setVisible(true);

	ancreLabel->setPosition("5%", "heightEb.bottom + 10");
	ancreLabel->setVisible(true);

	if (type == "rectangle") createShapeButton->connect("pressed", &Menu::createRectangle, this);
	else if (type == "ellipse") createShapeButton->connect("pressed", &Menu::createEllipse, this);
}

void Menu::display1ValueConstructor(std::string type) {
	displayDefault();

	singleLabel->setVisible(true);
	singleEb->setVisible(true);

	ancreLabel->setPosition("5%", "singleEb.bottom + 10");
	ancreLabel->setVisible(true);

	if (type == "cercle") {
		singleLabel->setText("Rayon");
		singleEb->setDefaultText("Nombre");
		createShapeButton->connect("pressed", &Menu::createCercle, this);
	}

	else if (type == "carre") {
		singleLabel->setText(std::string("Cot�"));
		singleEb->setDefaultText("Nombre");
		createShapeButton->connect("pressed", &Menu::createCarre, this);
	}

	else if (type == "image") {
		singleLabel->setText("Chemin vers l'image");
		singleEb->setDefaultText("chemin\\vers\\votre\\image.png");
		singleEb->setText("");
		createShapeButton->connect("pressed", &Menu::createImage, this);
	}
}


void Menu::hiddingAddShape() {
	widthLabel->setVisible(false);
	heightLabel->setVisible(false);
	singleLabel->setVisible(false);
	ancreLabel->setVisible(false);
	posXLabel->setVisible(false);
	posYLabel->setVisible(false);

	widthEb->setVisible(false);
	widthEb->setText("");
	heightEb->setVisible(false);
	heightEb->setText("");
	singleEb->setVisible(false);
	singleEb->setText("");
	posXEb->setVisible(false);
	posXEb->setText("");
	posYEb->setVisible(false);
	posYEb->setText("");

	closeAddShapeButton->setVisible(false);
	createShapeButton->setVisible(false);
}

void Menu::createPoint() {

	int x = NULL;
	int y = NULL;

	getXYValues(&x, &y);

	if (x != NULL && y != NULL) {
		std::cout << "x : " << x << ", y :" << y << std::endl;
	}
}

void Menu::createRectangle() {
	int x = NULL;
	int y = NULL;
	int largeur = NULL;
	int hauteur = NULL;

	getXYValues(&x, &y);
	get2Values(&largeur, &hauteur);

	if (x != NULL && y != NULL && largeur != NULL && hauteur != NULL) {
		std::cout << "x : " << x << ", y :" << y << "largeur : " << largeur << ", hauteur :" << hauteur << std::endl;
	}
}

void Menu::createEllipse() {
	int x = NULL;
	int y = NULL;
	int largeur = NULL;
	int hauteur = NULL;

	getXYValues(&x, &y);
	get2Values(&largeur, &hauteur);

	if (x != NULL && y != NULL && largeur != NULL && hauteur != NULL) {
		std::cout << "x : " << x << ", y :" << y << "largeur : " << largeur << ", hauteur :" << hauteur << std::endl;
	}
}

void Menu::createCarre() {
	int x = NULL;
	int y = NULL;
	int cote = NULL;

	getXYValues(&x, &y);
	get1Value(&cote);

	if (x != NULL && y != NULL && cote != NULL) {
		std::cout << "x : " << x << ", y :" << y << "cote : " << cote << std::endl;
	}
}

void Menu::createCercle() {
	int x = NULL;
	int y = NULL;
	int rayon = NULL;

	getXYValues(&x, &y);
	get1Value(&rayon);

	if (x != NULL && y != NULL && rayon != NULL) {
		std::cout << "x : " << x << ", y :" << y << "rayon : " << rayon << std::endl;
	}
}

void Menu::createImage() {

}




void Menu::getXYValues(int * x, int * y) {
	if (posXEb->getText().isEmpty()) {
		posXEb->getRenderer()->setBorderColor(sf::Color::Red);
		posXEb->setFocused(true);
	}
	else if (posYEb->getText().isEmpty()) {
		posYEb->getRenderer()->setBorderColor(sf::Color::Red);
		posYEb->setFocused(true);
	}

	try {
		*y = std::stoi((std::string) posYEb->getText());
	}
	catch (std::invalid_argument) {
		posYEb->getRenderer()->setBorderColor(sf::Color::Red);
		posYEb->setFocused(true);
	}

	try {
		*x = std::stoi((std::string) posXEb->getText());
	}
	catch (std::invalid_argument) {
		posXEb->getRenderer()->setBorderColor(sf::Color::Red);
		posXEb->setFocused(true);
	}
}

void Menu::get2Values(int * largeur, int * hauteur) {
	if (widthEb->getText().isEmpty()) {
		widthEb->getRenderer()->setBorderColor(sf::Color::Red);
		widthEb->setFocused(true);
	}
	else if (heightEb->getText().isEmpty()) {
		heightEb->getRenderer()->setBorderColor(sf::Color::Red);
		heightEb->setFocused(true);
	}

	try {
		*hauteur = std::stoi((std::string) heightEb->getText());
	}
	catch (std::invalid_argument) {
		heightEb->getRenderer()->setBorderColor(sf::Color::Red);
		heightEb->setFocused(true);
	}

	try {
		*largeur = std::stoi((std::string) widthEb->getText());
	}
	catch (std::invalid_argument) {
		widthEb->getRenderer()->setBorderColor(sf::Color::Red);
		widthEb->setFocused(true);
	}
}


void Menu::get1Value(int * single) {
	if (singleEb->getText().isEmpty()) {
		singleEb->getRenderer()->setBorderColor(sf::Color::Red);
		singleEb->setFocused(true);
	}

	try {
		*single = std::stoi((std::string) singleEb->getText());
	}
	catch (std::invalid_argument) {
		singleEb->getRenderer()->setBorderColor(sf::Color::Red);
		singleEb->setFocused(true);
	}
}