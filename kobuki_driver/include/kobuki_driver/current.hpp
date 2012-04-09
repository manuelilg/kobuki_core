#ifndef KOBUKI_CURRENT_DATA_HPP__
#define KOBUKI_CURRENT_DATA_HPP__

#include <ecl/containers.hpp>
#include "payload_base.hpp"
#include <kobuki_comms/Header.h>
#include <kobuki_comms/Current.h>

namespace kobuki
{

class CurrentData : public packet_handler::payloadBase
{
public:
  // container
  kobuki_comms::Current data;

  CurrentData()
  {
    data.current.resize(2);
  }

  // methods
  bool serialise(ecl::PushAndPop<unsigned char> & byteStream)
  {
    if (!(byteStream.size() > 0))
    {
      ROS_WARN_STREAM("kobuki_node: kobuki_current: serialise failed. empty byte stream.");
      return false;
    }

    buildBytes(data.header_id, byteStream);
    buildBytes(data.current[0], byteStream);
    buildBytes(data.current[1], byteStream);
    //buildBytes( data.current[2], byteStream );
    //buildBytes( data.current[3], byteStream );
    //buildBytes( data.current[4], byteStream );
    //buildBytes( data.current[5], byteStream );
    return true;
  }

  bool deserialise(ecl::PushAndPop<unsigned char> & byteStream)
  {
    if (!(byteStream.size() > 0))
    {
      ROS_WARN_STREAM("kobuki_node: kobuki_current: deserialise failed. empty byte stream.");
      return false;
    }

    buildVariable(data.header_id, byteStream);
    buildVariable(data.current[0], byteStream);
    buildVariable(data.current[1], byteStream);
    //buildVariable( data.current[2], byteStream );
    //buildVariable( data.current[3], byteStream );
    //buildVariable( data.current[4], byteStream );
    //buildVariable( data.current[5], byteStream );

    //showMe();
    return constrain();
  }

  bool constrain()
  {
    return true;
  }

  void showMe()
  {
    //printf("--[%02x || %03d | %03d | %03d]\n", data.bump, current[2], current[1], current[0] );
  }
};

} // namespace kobuki

#endif /* KOBUKI_CURRENT_DATA_HPP__ */
