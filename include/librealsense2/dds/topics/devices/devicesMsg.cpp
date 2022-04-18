// License: Apache 2.0. See LICENSE file in root directory.
// Copyright(c) 2022 Intel Corporation. All Rights Reserved.

/*!
 * @file devicesMsg.cpp
 * This source file contains the definition of the described types in the IDL file.
 *
 * This file was generated by the tool gen.
 */

#ifdef _WIN32
// Remove linker warning LNK4221 on Visual Studio
namespace {
char dummy;
}  // namespace
#endif  // _WIN32

#include "devicesMsg.h"
#include <fastcdr/Cdr.h>

#include <fastcdr/exceptions/BadParamException.h>
using namespace eprosima::fastcdr::exception;

#include <utility>


librealsense::dds::topics::devices::devices()
{
    // m_name com.eprosima.idl.parser.typecode.ArrayTypeCode@704921a5
    memset(&m_name, 0, (255) * 1);
    // m_serial_number com.eprosima.idl.parser.typecode.ArrayTypeCode@df27fae
    memset(&m_serial_number, 0, (255) * 1);
    // m_product_line com.eprosima.idl.parser.typecode.ArrayTypeCode@24a35978
    memset(&m_product_line, 0, (255) * 1);
    // m_locked com.eprosima.idl.parser.typecode.PrimitiveTypeCode@16f7c8c1
    m_locked = false;

}

librealsense::dds::topics::devices::~devices()
{




}

librealsense::dds::topics::devices::devices(
        const devices& x)
{
    m_name = x.m_name;
    m_serial_number = x.m_serial_number;
    m_product_line = x.m_product_line;
    m_locked = x.m_locked;
}

librealsense::dds::topics::devices::devices(
        devices&& x)
{
    m_name = std::move(x.m_name);
    m_serial_number = std::move(x.m_serial_number);
    m_product_line = std::move(x.m_product_line);
    m_locked = x.m_locked;
}

librealsense::dds::topics::devices& librealsense::dds::topics::devices::operator =(
        const devices& x)
{

    m_name = x.m_name;
    m_serial_number = x.m_serial_number;
    m_product_line = x.m_product_line;
    m_locked = x.m_locked;

    return *this;
}

librealsense::dds::topics::devices& librealsense::dds::topics::devices::operator =(
        devices&& x)
{

    m_name = std::move(x.m_name);
    m_serial_number = std::move(x.m_serial_number);
    m_product_line = std::move(x.m_product_line);
    m_locked = x.m_locked;

    return *this;
}

bool librealsense::dds::topics::devices::operator ==(
        const devices& x) const
{

    return (m_name == x.m_name && m_serial_number == x.m_serial_number && m_product_line == x.m_product_line && m_locked == x.m_locked);
}

bool librealsense::dds::topics::devices::operator !=(
        const devices& x) const
{
    return !(*this == x);
}

size_t librealsense::dds::topics::devices::getMaxCdrSerializedSize(
        size_t current_alignment)
{
    size_t initial_alignment = current_alignment;


    current_alignment += ((255) * 1) + eprosima::fastcdr::Cdr::alignment(current_alignment, 1);


    current_alignment += ((255) * 1) + eprosima::fastcdr::Cdr::alignment(current_alignment, 1);


    current_alignment += ((255) * 1) + eprosima::fastcdr::Cdr::alignment(current_alignment, 1);


    current_alignment += 1 + eprosima::fastcdr::Cdr::alignment(current_alignment, 1);



    return current_alignment - initial_alignment;
}

size_t librealsense::dds::topics::devices::getCdrSerializedSize(
        const librealsense::dds::topics::devices& data,
        size_t current_alignment)
{
    (void)data;
    size_t initial_alignment = current_alignment;


    if ((255) > 0)
    {
        current_alignment += ((255) * 1) + eprosima::fastcdr::Cdr::alignment(current_alignment, 1);
    }

    if ((255) > 0)
    {
        current_alignment += ((255) * 1) + eprosima::fastcdr::Cdr::alignment(current_alignment, 1);
    }

    if ((255) > 0)
    {
        current_alignment += ((255) * 1) + eprosima::fastcdr::Cdr::alignment(current_alignment, 1);
    }

    current_alignment += 1 + eprosima::fastcdr::Cdr::alignment(current_alignment, 1);



    return current_alignment - initial_alignment;
}

void librealsense::dds::topics::devices::serialize(
        eprosima::fastcdr::Cdr& scdr) const
{

    scdr << m_name;

    scdr << m_serial_number;

    scdr << m_product_line;

    scdr << m_locked;

}

void librealsense::dds::topics::devices::deserialize(
        eprosima::fastcdr::Cdr& dcdr)
{

    dcdr >> m_name;

    dcdr >> m_serial_number;

    dcdr >> m_product_line;

    dcdr >> m_locked;
}

/*!
 * @brief This function copies the value in member name
 * @param _name New value to be copied in member name
 */
void librealsense::dds::topics::devices::name(
        const std::array<char, 255>& _name)
{
    m_name = _name;
}

/*!
 * @brief This function moves the value in member name
 * @param _name New value to be moved in member name
 */
void librealsense::dds::topics::devices::name(
        std::array<char, 255>&& _name)
{
    m_name = std::move(_name);
}

/*!
 * @brief This function returns a constant reference to member name
 * @return Constant reference to member name
 */
const std::array<char, 255>& librealsense::dds::topics::devices::name() const
{
    return m_name;
}

/*!
 * @brief This function returns a reference to member name
 * @return Reference to member name
 */
std::array<char, 255>& librealsense::dds::topics::devices::name()
{
    return m_name;
}
/*!
 * @brief This function copies the value in member serial_number
 * @param _serial_number New value to be copied in member serial_number
 */
void librealsense::dds::topics::devices::serial_number(
        const std::array<char, 255>& _serial_number)
{
    m_serial_number = _serial_number;
}

/*!
 * @brief This function moves the value in member serial_number
 * @param _serial_number New value to be moved in member serial_number
 */
void librealsense::dds::topics::devices::serial_number(
        std::array<char, 255>&& _serial_number)
{
    m_serial_number = std::move(_serial_number);
}

/*!
 * @brief This function returns a constant reference to member serial_number
 * @return Constant reference to member serial_number
 */
const std::array<char, 255>& librealsense::dds::topics::devices::serial_number() const
{
    return m_serial_number;
}

/*!
 * @brief This function returns a reference to member serial_number
 * @return Reference to member serial_number
 */
std::array<char, 255>& librealsense::dds::topics::devices::serial_number()
{
    return m_serial_number;
}
/*!
 * @brief This function copies the value in member product_line
 * @param _product_line New value to be copied in member product_line
 */
void librealsense::dds::topics::devices::product_line(
        const std::array<char, 255>& _product_line)
{
    m_product_line = _product_line;
}

/*!
 * @brief This function moves the value in member product_line
 * @param _product_line New value to be moved in member product_line
 */
void librealsense::dds::topics::devices::product_line(
        std::array<char, 255>&& _product_line)
{
    m_product_line = std::move(_product_line);
}

/*!
 * @brief This function returns a constant reference to member product_line
 * @return Constant reference to member product_line
 */
const std::array<char, 255>& librealsense::dds::topics::devices::product_line() const
{
    return m_product_line;
}

/*!
 * @brief This function returns a reference to member product_line
 * @return Reference to member product_line
 */
std::array<char, 255>& librealsense::dds::topics::devices::product_line()
{
    return m_product_line;
}
/*!
 * @brief This function sets a value in member locked
 * @param _locked New value for member locked
 */
void librealsense::dds::topics::devices::locked(
        bool _locked)
{
    m_locked = _locked;
}

/*!
 * @brief This function returns the value of member locked
 * @return Value of member locked
 */
bool librealsense::dds::topics::devices::locked() const
{
    return m_locked;
}

/*!
 * @brief This function returns a reference to member locked
 * @return Reference to member locked
 */
bool& librealsense::dds::topics::devices::locked()
{
    return m_locked;
}


size_t librealsense::dds::topics::devices::getKeyMaxCdrSerializedSize(
        size_t current_alignment)
{
    size_t current_align = current_alignment;







    return current_align;
}

bool librealsense::dds::topics::devices::isKeyDefined()
{
    return false;
}

void librealsense::dds::topics::devices::serializeKey(
        eprosima::fastcdr::Cdr& scdr) const
{
    (void) scdr;
        
}



