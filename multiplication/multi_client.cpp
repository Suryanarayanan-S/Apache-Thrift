   #include "MultiplicationService.h"
   #include <transport/TSocket.h>
   #include <transport/TBufferTransports.h>
   #include <protocol/TBinaryProtocol.h>
   
   using namespace apache::thrift;
   using namespace apache::thrift::protocol;
   using namespace apache::thrift::transport;
   
   
   
   using namespace ::tutorial;
   
   int main(int argc, char **argv) {
     std::shared_ptr<TSocket> socket(new TSocket("localhost", 9094));
     std::shared_ptr<TTransport> transport(new TBufferedTransport(socket));
     std::shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));
  
     MultiplicationServiceClient client(protocol);
     transport->open();
     int mul=client.multiply(10,11);
     printf("%d super",mul);
     transport->close();
   
     return 0;
   }
