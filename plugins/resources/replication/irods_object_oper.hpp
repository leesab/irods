/* -*- mode: c++; fill-column: 132; c-basic-offset: 4; indent-tabs-mode: nil -*- */

#ifndef _object_oper_H_
#define _object_oper_H_

#include "irods_error.hpp"
#include "irods_file_object.hpp"

namespace irods {

    /**
     * @brief Class that holds a resource operation that needs to be replicated and the object on which it operated.
     */
    class object_oper {
    public:
        /// @brief ctor
        object_oper( void ) {}
        object_oper( const file_object& _file_object, const std::string& _operation );
        virtual ~object_oper( void );

        const file_object& object( void ) const {
            return file_object_;
        }
        const std::string& operation( void ) const {
            return operation_;
        }

        file_object& object( void ) {
            return file_object_;
        }
        std::string& operation( void ) {
            return operation_;
        }

    private:
        file_object file_object_;
        std::string operation_;
    };
}; // namespace irods

#endif // _object_oper_H_
