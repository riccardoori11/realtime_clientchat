#include <iostream>
#include <string>
#include <string_view>
#include <uwebsockets/App.h>
#include <uwebsockets/WebSocketProtocol.h>

struct Stats{
		
		int activeConnections{0};
		int totalConnections{0};
		int messageCount{0};
		
		std::string tojson(){
				
				return
						
						"{"
						"\"Active connections\":"  + std::to_string(activeConnections) + ","
						"\"Total connections\":"  + std::to_string(totalConnections) + ","
						"\"Message Count\":"  + std::to_string(messageCount) + "} \n";
		}
		



};

int main(){
		
		Stats stats;

		uWS::App::WebSocketBehavior<std::string> behaviour;
		
		behaviour.open = [&stats](auto *ws){
				
				++stats.activeConnections;
				++stats.totalConnections;
				std:: cout<< "Client has connected. Active connections:" << stats.activeConnections<< "\n";
				ws->subscribe("Chat");
		};

		behaviour.message = [&stats](auto *ws,std::string_view message, uWS::OpCode opcode){
				
				stats.messageCount++;
				ws->publish("Chat",message, opcode);
		};
		behaviour.close = [&stats](auto *ws, int code,std::string_view message){
				
				stats.activeConnections--;
				std::cout<<"Client has disconnected. Active connections:"<< stats.activeConnections << "\n";

		}; 
		uWS::App()
				.ws<std::string>("/*",std::move(behaviour))
				.get("/stats", [&stats](auto* res, auto* req){
						
								res ->writeHeader("Content-Type","applications/json");
								res -> end(stats.tojson());


										})
				.listen(9001,[](auto *listenSocket){
								
						if (listenSocket){
								std::cout<<"Server has started. Stats are available at http://localhost:9001/stats"<< "\n" ;
						}else{
								std::cerr<<"Server failed to start\n"<<std::endl;
						}

								}).run();


}

