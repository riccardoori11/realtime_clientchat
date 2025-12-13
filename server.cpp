#include <uwebsockets/App.h>
#include <iostream>
#include <uwebsockets/WebSocketProtocol.h>


int main(){
		
		
		
    uWS::App::WebSocketBehavior<std::string> behavior;
			
		
				behavior.open = [](auto *ws){
						
						std::cout << "Client has connected \n"<< std::endl;
						ws -> subscribe("chat");

				};
				behavior.message = [](auto *ws, std::string_view message, uWS::OpCode opcode){
						
						ws -> publish("chat",message,opcode);

				};
				behavior.close = [](auto *ws,int code,std::string_view message){
						
						std::cout <<"Client has disconnected"<< std::endl;
				};
			

				uWS::App()
						.ws<std::string>("/*",std::move(behavior))
						.listen(9001,[] (auto *ListenSocket){

								if (ListenSocket){
										
										std::cout<< "Server has started on port 9001\n"<< std::endl;

								}else{
										std::cerr<< "Failed to listen to port 9001"<<std::endl;
								}


						}).run();
				


}


	



