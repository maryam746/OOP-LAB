
#include <iostream>
#include <string>

using namespace std;

class Ticket {
protected:
    int ticketID;
    string passengerName;
    double price;
    string date;
    string destination;

public:
    Ticket(int id, string name, double p, string d, string dest)
        : ticketID(id), passengerName(name), price(p), date(d), destination(dest) {}

    virtual void reserve() {
        cout << "Ticket reserved for " << passengerName << endl;
    }

    virtual void cancel() {
        cout << "Ticket cancelled for " << passengerName << endl;
    }

    virtual void displayTicketInfo() const {
        cout << "Ticket ID: " << ticketID << "\nPassenger: " << passengerName
             << "\nPrice: $" << price << "\nDate: " << date << "\nDestination: " << destination << endl;
    }

    virtual ~Ticket() {}
};

class FlightTicket : public Ticket {
private:
    string airlineName;
    string flightNumber;
    string seatClass;

public:
    FlightTicket(int id, string name, double p, string d, string dest,
                 string airline, string flightNo, string sClass)
        : Ticket(id, name, p, d, dest),
          airlineName(airline), flightNumber(flightNo), seatClass(sClass) {}

    void displayTicketInfo() const override {
        Ticket::displayTicketInfo();
        cout << "Airline: " << airlineName << "\nFlight No: " << flightNumber
             << "\nSeat Class: " << seatClass << endl;
    }
};

class TrainTicket : public Ticket {
private:
    string trainNumber;
    string coachType;
    string departureTime;
    static int seatCounter;

public:
    TrainTicket(int id, string name, double p, string d, string dest,
                string trainNo, string coach, string time)
        : Ticket(id, name, p, d, dest),
          trainNumber(trainNo), coachType(coach), departureTime(time) {}

    void reserve() override {
        seatCounter++;
        cout << "Train ticket reserved. Auto-assigned Seat #" << seatCounter << endl;
    }

    void displayTicketInfo() const override {
        Ticket::displayTicketInfo();
        cout << "Train No: " << trainNumber << "\nCoach: " << coachType
             << "\nDeparture Time: " << departureTime << endl;
    }
};
int TrainTicket::seatCounter = 0;

class BusTicket : public Ticket {
private:
    string busCompany;
    int seatNumber;

public:
    BusTicket(int id, string name, double p, string d, string dest,
              string company, int seat)
        : Ticket(id, name, p, d, dest),
          busCompany(company), seatNumber(seat) {}

    void cancel() override {
        cout << "Bus ticket for " << passengerName << " cancelled. Full refund eligible (last-minute)." << endl;
    }

    void displayTicketInfo() const override {
        Ticket::displayTicketInfo();
        cout << "Bus Company: " << busCompany << "\nSeat No: " << seatNumber << endl;
    }
};

class ConcertTicket : public Ticket {
private:
    string artistName;
    string venue;
    string seatType;

public:
    ConcertTicket(int id, string name, double p, string d, string dest,
                  string artist, string v, string seatT)
        : Ticket(id, name, p, d, dest),
          artistName(artist), venue(v), seatType(seatT) {}

    void displayTicketInfo() const override {
        Ticket::displayTicketInfo();
        cout << "Artist: " << artistName << "\nVenue: " << venue
             << "\nSeat Type: " << seatType << endl;
    }
};

// Main demonstration
int main() {
    FlightTicket ft(1001, "Alice", 500.0, "2025-05-20", "New York", "Delta Airlines", "DL123", "Business");
    TrainTicket tt(1002, "Bob", 75.0, "2025-05-21", "Chicago", "TR567", "AC", "09:00 AM");
    BusTicket bt(1003, "Charlie", 30.0, "2025-05-22", "Boston", "Greyhound", 17);
    ConcertTicket ct(1004, "Diana", 120.0, "2025-05-25", "Los Angeles", "The Weeknd", "Staples Center", "VIP");

    cout << "--- Flight Ticket ---\n";
    ft.reserve();
    ft.displayTicketInfo();

    cout << "\n--- Train Ticket ---\n";
    tt.reserve();
    tt.displayTicketInfo();

    cout << "\n--- Bus Ticket ---\n";
    bt.reserve();
    bt.displayTicketInfo();
    bt.cancel();

    cout << "\n--- Concert Ticket ---\n";
    ct.reserve();
    ct.displayTicketInfo();

    return 0;
}

