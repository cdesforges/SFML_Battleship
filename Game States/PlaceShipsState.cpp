//
// Created by Chandler Desforges on 6/8/24.
//

#include "PlaceShipsState.h"

#include <utility>

PlaceShipsState::PlaceShipsState(sf::RenderWindow &window, StateManager &stateManager, MusicPtr music) : State(window, stateManager),
m_title("Battleship",{800,30},50),
m_dt(0.f),
m_music(std::move(music)),
m_startButton(50,{600,600},"start"),
m_shipPalette({500.f, 200.f})
{}

void PlaceShipsState::eventHandler()
{
    m_dt = m_clock.restart().asSeconds();

    sf::Event event;

    while(m_window.pollEvent(event))
    {
        switch(event.type)
        {
            case sf::Event::Closed:
                m_window.close(); // close window
                break;

            case sf::Event::MouseButtonPressed:
                selectShip(event); // set drag offset and attack ship with cursor
                checkForStart(); // was the start button pressed
                break;

            case sf::Event::MouseMoved:
                dragShip(event);

            case sf::Event::MouseButtonReleased:
                releaseShip(event); // Release the selected ship
                break;

            case sf::Event::KeyPressed:
                rotateShip(event); // rotate the selected ship
                break;
        }
    }
}

void PlaceShipsState::update()
{
    //update
    updateCursor();
    updateHoveredSquares();
//    snapShips();  //TODO: fix this awful function

    m_p1.update(m_dt);
    m_startButton.update(m_window);
}

void PlaceShipsState::draw()
{
    m_window.draw(m_p1);
    m_window.draw(m_title);
    m_window.draw(m_shipPalette);
    m_window.draw(m_startButton);
}

void PlaceShipsState::checkForStart()
{
    if(m_startButton.contains(sf::Mouse::getPosition(m_window)))
    {
        std::cout << "Made it here\n";

        addShipsToPlayer();
        m_p1.resetSquares();
        m_stateManager.replaceState(std::make_shared<MainGameState>(m_window, m_stateManager, m_p1));
    }
}

void PlaceShipsState::updateCursor()
{
    // if a ship in the pallet is hovered
    if (m_shipPalette.isShipHovered(m_window))
        m_cursor.loadFromSystem(sf::Cursor::Hand);
    else
        m_cursor.loadFromSystem(sf::Cursor::Arrow);

    m_window.setMouseCursor(m_cursor);
}

void PlaceShipsState::selectShip(sf::Event &event)
{
    if (event.mouseButton.button == sf::Mouse::Left)
        m_shipPalette.selectShip(m_window);
}

void PlaceShipsState::dragShip(sf::Event& event)
{
    m_shipPalette.dragShip(m_window);
}

void PlaceShipsState::updateHoveredSquares()
{
    m_p1.resetSquares();

    for (auto &ship : m_shipPalette.getShips())
        if(ship->getIsVisible())
            m_p1.setHoveredSquares(ship);
}

void PlaceShipsState::addShipsToPlayer()
{
    for(auto& ship : m_shipPalette.getShips())
        ship->setIsVisible(false);

    m_p1.addShips(m_shipPalette.getShips());
}

void PlaceShipsState::releaseShip(sf::Event& event)
{
    if (event.mouseButton.button == sf::Mouse::Left)
        m_shipPalette.releaseShip();
}

void PlaceShipsState::rotateShip(sf::Event& event)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
        m_shipPalette.rotateShip();
}

void PlaceShipsState::snapShips()
{
    m_shipPalette.setSelectedShipPosition({m_p1.getPositionOfHoveredSquare({(float)sf::Mouse::getPosition(m_window).x, (float)sf::Mouse::getPosition(m_window).y}).x + 30,
                                          m_p1.getPositionOfHoveredSquare({(float)sf::Mouse::getPosition(m_window).x, (float)sf::Mouse::getPosition(m_window).y}).y + 20});
}
